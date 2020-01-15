#include "Generator.h"
#include "Pipe.h"
#include "LowPass.h"

#include <iostream>
#include <thread> 
#include <chrono>         // namespace chrono
#include <random>

using namespace std;
using namespace chrono;
using namespace chrono_literals;

static std::random_device rd;  //Will be used to obtain a seed for the random number engine
static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
static std::uniform_int_distribution<> dist(100, 1000);


std::unique_ptr<Event> Generator::operator()()
{
  return generate_event();
}


std::unique_ptr<Event> Generator::generate_event()
{
    int nr = (rand() % 3);
  this_thread::sleep_for(1s);
  // this_thread::sleep_for(std::chrono::milliseconds{dist(gen)});

  std::unique_ptr<Event> ptr{};
  switch(nr)
  {
  case 0:
    {
      ptr =  make_unique<Event>(Event::Type::ADVISORY);
      break;
    }
  case 1:
    {
      ptr = make_unique<Event>(Event::Type::WARNING);
      break;
    }
  case 2:
    {
      ptr = make_unique<Event>(Event::Type::CAUTION);
      break;
    }
  }
  return ptr;
}

