#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <sstream>
 
 // std::atomic_flag - atomic Boolean type, are guaranteed not locked
 // initialization, reset the status (false)
std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;


void append_number(int x) {
    // test_and_set change the status to true, adopts synchronization order memory for this operation
    while (lock_stream.test_and_set()) {}
    stream << "thread #" << x << '\n';
    // clear - change the status to false, the synchronization order memory for this operation
    lock_stream.clear();
}

 
int main ()
{
  std::vector<std::thread> threads;
  for (int i=1; i <= 10; ++i) threads.push_back(std::thread(append_number,i));
  for (auto& th : threads) th.join();

  std::cout << stream.str();
  return 0;
}