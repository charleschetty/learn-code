#include <cmath>
#include <concepts>
#include <condition_variable>
#include <future>
#include <iostream>
#include <math.h>
#include <memory>
#include <mutex>
#include <set>
#include <string>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T>
concept is_int = std::is_integral<T>::value;

template <is_int T> auto add(T a, T b) -> T { return a + b; }

template <typename T>
concept Check = requires(T a, T b) {
  { a + b } -> std::same_as<T>;
};
template <Check T> T add1(T a, T b) { return a + b; }

// void init() { cout << "init" << endl; }

// void worker(std::once_flag *flag) { std::call_once(*flag, init); }

static double sum = 0;
static std::mutex sum_mutex;

void worker(int min, int max) {
  double temp_sum = 0;
  for (int i = min; i < max; i++) {
    temp_sum += sqrt(i);
  }
  sum_mutex.lock();
  sum += temp_sum;
  sum_mutex.unlock();
}

void concurent_work(int min, int max) {
  auto start_time = std::chrono::steady_clock::now();
  unsigned count = std::thread::hardware_concurrency();
  cout << "hardware_concurrency:" << count << std::endl;
  vector<std::thread> threads;
  int range_num = (max - min) / count;
  int min_temp = min;
  for (int i = 0; i < count; i++) {
    int range = range_num * (i + 1);
    threads.push_back(
        std::thread(worker, min + range_num * i, min + range_num * (i + 1)));
  }
  for (auto &t : threads) {
    t.join();
  }

  auto end_time = std::chrono::steady_clock::now();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                  start_time)
                .count();
  cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << sum
       << endl;
}

class Account {
public:
  Account(std::string name, double money) : mName(name), mMoney(money){};
  // void changemoney(double amount) { mMoney += amount; }
  void changemoney(double amount) {
    std::unique_lock lock(mMoneylock);
    mcondition.wait(lock, [this, amount] { return mMoney + amount > 0; });
    mMoney += amount;
    mcondition.notify_all();
  }
  std::string getname() { return mName; }
  double getmoney() { return mMoney; }
  std::mutex *getlock() { return &mMoneylock; }

private:
  std::string mName;
  std::mutex mMoneylock;
  double mMoney;
  std::condition_variable mcondition;
};

class Bank {
public:
  void addAccount(Account *account) { mAccount.insert(account); }
  // bool transferMoney(Account *accountA, Account *accountB, double amount) {
  //   std::lock(*accountA->getlock(), *accountB->getlock());
  //
  //   std::lock_guard guardA(*accountA->getlock(), std::adopt_lock);
  //   std::lock_guard guardB(*accountB->getlock(), std::adopt_lock);
  //   if (amount > accountA->getmoney()) {
  //     return false;
  //   }
  //   accountA->changemoney(-amount);
  //   accountB->changemoney(amount);
  //   return true;
  // }
  void transferMoney(Account *accountA, Account *accountB, double amount) {
    accountA->changemoney(-amount);
    accountB->changemoney(amount);
  }
  double totalMoney() const {
    double sum = 0;
    for (auto a : mAccount) {
      sum += a->getmoney();
    }
    return sum;
  }

private:
  std::set<Account *> mAccount;
};
std::mutex scoutlock;
// void randomTransfer(Bank *bank, Account *accountA, Account *accountB) {
//   while (true) {
//     double randomMoney = ((double)rand() / RAND_MAX) * 100;
//     if (bank->transferMoney(accountA, accountB, randomMoney)) {
//       scoutlock.lock();
//       cout << "Transfer " << randomMoney << " from " << accountA->getname()
//            << " to " << accountB->getname()
//            << ", Bank totalMoney: " << bank->totalMoney() << endl;
//       scoutlock.unlock();
//     } else {
//       scoutlock.lock();
//       cout << "Transfer failed, " << accountA->getname() << " has only $"
//            << accountA->getmoney() << ", but " << randomMoney << " required"
//            << endl;
//       scoutlock.unlock();
//     }
//   }
// }
void randomTransfer(Bank *bank, Account *accountA, Account *accountB) {
  while (true) {
    double randomMoney = ((double)rand() / RAND_MAX) * 100;
    {
      std::lock_guard guard(scoutlock);
      cout << "Try to Transfer " << randomMoney << " from "
           << accountA->getname() << "(" << accountA->getmoney() << ") to "
           << accountB->getname() << "(" << accountB->getmoney()
           << "), Bank totalMoney: " << bank->totalMoney() << endl;
    }
    bank->transferMoney(accountA, accountB, randomMoney);
  }
}

static double sum1 = 0;
void worker1(int min, int max) {
  for (int i = min; i < max; i++) {
    sum += sqrt(i);
  }
}

double current_worker(int min, int max) {
  double sum = 0;
  for (int i = min; i <= max; i++) {
    sum += sqrt(i);
  }
  return sum;
}

double concurent_task(int min, int max) {
  vector<std::future<double>> result;
  unsigned current_count = std::thread::hardware_concurrency();
  min = 0;
  for (int i = 0; i < current_count; i++) {
    std::packaged_task<double(int, int)> task(current_worker);
    result.push_back(task.get_future());
    int range = max / current_count * (i + 1);
    std::thread t(std::move(task), min, max);
    t.detach();
    min = range + 1;
  }
  cout << "thread creat finished" << endl;
  double sum = 0;
  for (auto &r : result) {
    sum += r.get();
  }
  return sum;
}

void concurent_task1(int min, int max, std::promise<double> *res) {
  vector<std::future<double>> result;
  unsigned current_count = std::thread::hardware_concurrency();
  min = 0;
  for (int i = 0; i < current_count; i++) {
    std::packaged_task<double(int, int)> task(current_worker);
    result.push_back(task.get_future());
    int range = max / current_count * (i + 1);
    std::thread t(std::move(task), min, max);
    t.detach();
    min = range + 1;
  }
  cout << "thread creat finished" << endl;
  double sum = 0;
  for (auto &r : result) {
    sum += r.get();
  }
  res->set_value(sum);
  cout << "finish" << endl;
}
auto main() -> int {
  double r = concurent_task(0, 1000);
  cout << "r:" << r << endl;
  std::promise<double> sum;
  concurent_task1(0, 1000, &sum);
  cout<<"res:"<<sum.get_future().get()<<endl;
  // double res = 0;
  // cout << "this thread id" << std::this_thread::get_id() << endl;
  // auto fi = std::async(std::launch::async, [&res] {
  //   cout << "async id:" << std::this_thread::get_id() << endl;
  //   for (int i = 0; i <= 1000; i++) {
  //     res += sqrt(i);
  //   }
  // });
  // fi.wait();
  // cout << "res:" << res << endl;
  // Account a("perl", 100);
  // Account b("memr", 100);
  // Bank abank;
  // abank.addAccount(&a);
  // abank.addAccount(&b);
  // std::thread t1(randomTransfer, &abank, &a, &b);
  // std::thread t2(randomTransfer, &abank, &b, &a);
  // t1.join();
  // t2.join();
  // concurent_work(1, 1000);
  // auto is_int = std::is_integral<int>::value;
  // std::cout << is_int << std::endl;
  // std::cout << add(2, 1) << std::endl;
  // std::cout << add1(1.1, 2.1) << std::endl;
  //
  // std::once_flag flag;
  //
  // std::thread t1(worker, &flag);
  // std::thread t2(worker, &flag);
  //
  // t1.join();
  // t2.join();
  return 0;
}
