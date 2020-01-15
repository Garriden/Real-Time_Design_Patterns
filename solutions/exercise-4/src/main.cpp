#ifndef TDD     // DO NOT REMOVE

#include "Event.h"
#include "Pipe.h"
#include "Generator.h"
#include "LowPass.h"
#include "Display.h"


int main()
{
  Pipe      pipe1{};
  Pipe      pipe2{};
  Generator generator{ pipe1 };
  LowPass   low_pass { pipe1, pipe2 };
  // LowPass   low_pass { pipe1, pipe2, Event::Type::CAUTION };
  Display   display{ pipe2 };
  
  for(unsigned i = 0; i < 10; ++i)
  {
    generator.execute();
    // low_pass.execute();
    // display.execute();
  }
  for(unsigned i = 0; i < 10; ++i)
  {
    // generator.execute();
    low_pass.execute();
    // display.execute();
  }
  for(unsigned i = 0; i < 10; ++i)
  {
    // generator.execute();
    // low_pass.execute();
    display.execute();
  }
}


// DO NOT REMOVE
#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#endif