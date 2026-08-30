#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
template<typename T>
class ThreadSafeQueue {
    std::queue<T>queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
public:
    void push(T item) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(std::move(item));
        cv_.notify_one();
    }
    void wait_and_pop(T& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]{ return !queue_.empty(); });
        item = std::move(queue_.front());
        queue_.pop();
    }
};

using std::this_thread::sleep_for;
using std::chrono::seconds;

std::queue<int> que;
std::mutex mtx;
std::condition_variable cv;
bool flag = false;



int main() {

    ThreadSafeQueue<int> que;

    std::thread producer([&que] () {
       for (int i = 0; i < 10; i++) {
           que.push(i);
       }
    });

    std::thread consumer([&que] () {
       while (true) {
           int val;
           que.wait_and_pop(val);
           std::cout << val << std::endl;
       }
    });
    consumer.join();
    producer.join();
    return 0;
}
