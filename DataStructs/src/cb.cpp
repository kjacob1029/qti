#include <iostream>
#include <thread>

#include <boost/circular_buffer.hpp>

const int maxQSize=3;
const int maxElems=10;

boost::circular_buffer<int> cb(maxQSize);

void producer()
{
  std::cout << "Thread: Producer" << std::endl;
  for (auto i=0; i<maxElems; i++) {
    while (cb.full());
    std::cout << "Produce: " << i << std::endl;
    cb.push_back(i);
  }
}

int main(int argc, char* argv[])
{
  std::thread t1(producer);

  int n=0;
  int i;
  while (n<maxElems) { 
    while (cb.empty());
    i = cb.front();
    std::cout << "Pop: " << i << std::endl;
    cb.pop_front();
    n++;
  }

  t1.join();

  return 0;
}
