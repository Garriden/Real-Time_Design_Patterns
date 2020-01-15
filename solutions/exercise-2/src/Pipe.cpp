#include "Pipe.h"
#include <iostream>

using namespace std;

void Pipe::push(const Event& in)
{
  // Copy the event.
  //
  event = in;
}

void Pipe::pull(Event& out)
{
  out = event;
  event = Event{ Event::Type::UNKNOWN };
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
