#include "Pipe.h"
#include <iostream>

using namespace std;

void Pipe::push(const Event& in)
{
  // Copy the event.
  //
  if( (next_in+1)%array_size != next_out) {
    eventList[next_in++] = in;
    if(next_in == array_size) {
      next_in = 0;
    }
  }
}

void Pipe::pull(Event& out)
{
  if(next_out != next_in) {
      out = eventList[next_out++];
  }
  else {
    out = Event{ Event::Type::UNKNOWN };
  }
  if(next_out == array_size) {
    next_out = 0;
  }
}

#ifdef TDD
#include "doctest.h"

TEST_CASE("Initial pipe") {
    Pipe      pipe{};
    Event e{};
    pipe.pull(e);
    CHECK( e.type() == Event::Type::UNKNOWN);
}

TEST_CASE("Simple push-pull") {
    Pipe      pipe{};
    pipe.push(Event{ Event::Type::WARNING });
    Event e{};
    pipe.pull(e);
    CHECK( e.type() == Event::Type::WARNING);
}

TEST_CASE("Simple two-pulls") {
    Pipe      pipe{};
    pipe.push(Event{ Event::Type::WARNING });
    Event e{};
    pipe.pull(e);
    pipe.pull(e);
    CHECK( e.type() == Event::Type::UNKNOWN);
}

#endif
