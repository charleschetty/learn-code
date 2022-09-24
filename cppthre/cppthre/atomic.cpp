#include <assert.h>
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y() {
  x.store(true, std::memory_order_relaxed);
  y.store(true, std::memory_order_release);
}

void read_y_thren_x() {
  while (y.load(std::memory_order_acquire)) {
    if (x.load(std::memory_order_relaxed)) {
      ++z;
    }
  }
}
void w_x_t_y_1() {
  x.store(true, std::memory_order_relaxed);
  std::atomic_thread_fence(std::memory_order_release);
  y.store(true, std::memory_order_relaxed);
}

void r_y_tx_1() {
  while (!y.load(std::memory_order_relaxed)) {
    std::atomic_thread_fence(std::memory_order_acquire);
    if (x.load(std::memory_order_relaxed)) {
      ++z;
    }
  }
}

int main() {
  x = false;
  y = false;
  z = 0;
  std::cout << x << std::endl;
  std::thread a(write_x_then_y);
  std::thread b(read_y_thren_x);
  a.join();
  b.join();
  assert(z.load() != 0);
  return 0;
}
