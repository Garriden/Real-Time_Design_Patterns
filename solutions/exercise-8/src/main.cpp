#ifndef TDD     // DO NOT REMOVE

#include "Event.h"
#include "Pipe.h"
#include "Generator.h"
#include "LowPass.h"
#include "Display.h"

#include <functional>
#include <thread> 
#include <chrono>         // namespace chrono

using namespace std;
using namespace chrono;
using namespace chrono_literals;

int main()
{
  Display   display{ };
  LowPass   low_pass { display };
  Generator generator{ low_pass };

  std::thread t1 { [&generator](){ for(int i = 0; i < 10; ++i) { generator(); this_thread::sleep_for(2s);} } };
  std::thread t2 { [&low_pass]() { do { low_pass(); } while(true);} };
  std::thread t3 { [&display]()  { do { display(); } while(true);} };
  t1.join();
}


// DO NOT REMOVE
#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#endif