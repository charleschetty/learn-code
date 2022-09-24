#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
using std::cout;
using std::endl;

template <typename T> class Safequeue {
private:
  std::queue<T> m_queue;
  std::mutex m_mutex;

public:
  Safequeue() {}
  Safequeue(Safequeue &&other) {}
  ~Safequeue() {}
  bool empty() {
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.empty();
  }
  int size() {
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.size();
  }
  void enqueue(T &t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.emplace(t);
  }
  bool dequeue(T &t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_queue.empty()) {
      return false;
    }
    t = std::move(m_queue.front());
    m_queue.pop();
    return true;
  }

  template <typename F, typename... Args>
  auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))> {
    std::function<decltype(f(args...)())> func =
        std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    auto task_ptr =
        std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
    std::function<void()> warpper_func = [task_ptr]() { (*task_ptr)(); };
    m_queue.enqueue(warpper_func);
  }
};
class ThreadPool {
private:
  class ThreadWorker {
  private:
    int m_id;
    ThreadPool *m_pool;

  public:
    ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id) {}
    void operator()() { std::function<void()> func; }
  };
};
int main() {
  cout << "1" << endl;
  return 0;
}
