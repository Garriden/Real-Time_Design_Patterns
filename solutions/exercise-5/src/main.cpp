#ifndef TDD     // DO NOT REMOVE

#include "Event.h"
#include "Pipe.h"
#include "Generator.h"
#include "LowPass.h"
#include "Display.h"

#include <functional>

int main()
{
  Pipe      pipe1{};
  Pipe      pipe2{};
  Generator generator{ pipe1 };
  LowPass   low_pass { pipe1, pipe2 };
  // LowPass   low_pass { pipe1, pipe2, Event::Type::CAUTION };
  Display   display{ pipe2 };

  std::array<std::function<void(void)>, 3> runnables {{ generator, low_pass, display }};
  
  for(unsigned i = 0; i < 10; ++i)
  {
    for(auto& fn : runnables ) {
      fn();
    }
  }

}


// DO NOT REMOVE
#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#endif