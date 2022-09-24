#include <chrono>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::string;
using std::thread;

void fuick() { cout << "fuck" << endl; }

class scoped_thread {
  thread thrd1;

public:
  explicit scoped_thread(thread th1) : thrd1(std::move(th1)) {
    if (!thrd1.joinable()) {
      throw std::logic_error("No thread");
    }
  }
  ~scoped_thread() { thrd1.join(); }

  scoped_thread(scoped_thread &) = delete;
  auto operator=(scoped_thread const &) -> scoped_thread & = delete;
};

class sleeper {
public:
  explicit sleeper(int &inte1) : inte1(inte1){};
  void operator()(int kint) {
    for (unsigned int j = 0; j <= 5; ++j) {
      std::this_thread::sleep_for(std::chrono::microseconds(100));
      inte1 += kint;
    }
    cout << std::this_thread::get_id() << endl;
  }

private:
  int &inte1;
};

mutex workermutex;
class worker {
public:
  explicit worker(string n) : name(n){};
  void operator()() {
    for (int i = 1; i <= 3; ++i) {
      std::this_thread::sleep_for(std::chrono::microseconds(200));
      workermutex.lock();
      cout << name << ":"
           << "Work" << i << "done" << endl;
      workermutex.unlock();
    }
  }

private:
  string name;
};

struct cradeadlock {
  std::mutex mut;
} __attribute__((aligned(64)));

void deadlock(cradeadlock &amutex, cradeadlock &bmutex) {
  // amutex.mut.lock();
  std::unique_lock<mutex> guard(amutex.mut, std::defer_lock);
  cout << "get first mutex" << endl;
  std::this_thread::sleep_for(std::chrono::microseconds(1));
  // bmutex.mut.lock();
  std::unique_lock<mutex> guard2(bmutex.mut, std::defer_lock);
  cout << "get second mutex" << endl;
  // amutex.mut.unlock();
  // bmutex.mut.unlock();
  std::lock(guard, guard2);
}

std::once_flag onceflag1;

void f1() {
  std::call_once(onceflag1, [] { cout << "1" << endl; });
}
void f2() {
  std::call_once(onceflag1, [] { cout << "2" << endl; });
}

mutex countmutex;
thread_local string s("hello");
void testlocal(string const & str1){
  s+=str1;
  std::lock_guard<mutex> guard(countmutex);
  cout<<s<<endl;
  cout<<endl;
}

auto main() -> int {
  thread t1(testlocal,"t1");
  thread t2(testlocal ,"t2");
  t1.join();t2.join();
  // thread t1(f1);
  // thread t2(f1);
  // thread t3(f2);
  // t1.join();
  // t2.join();
  // t3.join();

  // cradeadlock c1;
  // cradeadlock c2;
  // thread thread1([&] { deadlock(c1, c2); });
  // thread thread2([&] { deadlock(c2, c1); });
  // thread1.join();
  // thread2.join();

  // cout << "fuck" << endl;

  // thread thread1(fuick);
  // thread1.join();
  // thread1.detach();
  // cout << thread1.joinable() << endl;
  // int val1 = 1000;
  // thread thresleep(sleeper(val1), 5);
  // thresleep.join();
  // cout << val1 << endl;
  // cout << endl;
  // thread herb = thread(worker("herb"));
  // thread andre = thread(worker("andre"));
  // thread sctt = thread(worker("scott"));
  // thread njan = thread(worker("njan"));
  // herb.join();
  // andre.join();
  // sctt.join();
  // njan.join();
  // cout << endl;

  return 0;
}
