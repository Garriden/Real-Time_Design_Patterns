#include "Pipe.h"
#include <iostream>

using namespace std;

void Pipe::push(const Event& in)
{
  // Copy the event.
  //
  event = in;
}

std::optional<Event> Pipe::pull()
{
  if(event != Event{ Event::Type::UNKNOWN })
    return event;
  else
    return std::nullopt;
}

#ifdef TDD
#include "doctest.h"

TEST_CASE("Initial pipe") {
    Pipe pipe{};
    auto e = pipe.pull();
    CHECK( e == std::nullopt);
}

TEST_CASE("Simple push-pull") {
    Pipe      pipe{};
    pipe.push(Event{ Event::Type::WARNING });
    auto e = pipe.pull();
    CHECK( e.value().type() == Event::Type::WARNING);
}

TEST_CASE("Simple two-pulls") {
    Pipe      pipe{};
    pipe.push(Event{ Event::Type::WARNING });
    auto e = pipe.pull();
    e = pipe.pull();
    CHECK( e == std::nullopt);
}

#endif
