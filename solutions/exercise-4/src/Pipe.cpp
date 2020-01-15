#include "Pipe.h"
#include <iostream>

using namespace std;

void Pipe::push(std::unique_ptr<Event> in)
{
  // Copy the event.
  //
  if( (next_in+1)%array_size != next_out) {
    eventList[next_in++] = std::move(in);
    if(next_in == array_size) {
      next_in = 0;
    }
  }
}

std::unique_ptr<Event> Pipe::pull()
{
  std::unique_ptr<Event> rv{};
  if(next_out != next_in) {
      rv = std::move(eventList[next_out++]);
      if(next_out == array_size) {
        next_out = 0;
      }
  }
  return rv;
}

#ifdef TDD
#include "doctest.h"

TEST_CASE("Initial pipe") {
    Pipe      pipe{};
    auto e{ pipe.pull() };
    CHECK( e == nullptr);
}

TEST_CASE("Simple push-pull") {
    Pipe      pipe{};
    pipe.push(std::make_unique<Event>(Event::Type::WARNING));
    auto e{ pipe.pull() };
    CHECK( e->type() == Event::Type::WARNING);
}

TEST_CASE("Simple push-pull move") {
    Pipe      pipe{};
    auto ptr = std::make_unique<Event>(Event::Type::WARNING);
    pipe.push(std::move(ptr));
    CHECK( ptr == nullptr );
    auto e { pipe.pull() };
    CHECK( e->type() == Event::Type::WARNING );
}

TEST_CASE("Simple two-pulls") {
    Pipe      pipe{};
    pipe.push(std::make_unique<Event>(Event::Type::WARNING));
    auto e { pipe.pull() };

    CHECK( e->type() == Event::Type::WARNING);

    e = pipe.pull();
    CHECK( e == nullptr);
}


TEST_CASE("multiple-push-pulls") {
    Pipe      pipe{};
    pipe.push(std::make_unique<Event>(Event::Type::ADVISORY));
    pipe.push(std::make_unique<Event>(Event::Type::WARNING));
    pipe.push(std::make_unique<Event>(Event::Type::CAUTION));
    auto e { pipe.pull() };
    CHECK( e->type() == Event::Type::ADVISORY);
    e = pipe.pull();
    CHECK( e->type() == Event::Type::WARNING);
    e = pipe.pull();
    CHECK( e->type() == Event::Type::CAUTION);
    e = pipe.pull();
    CHECK( e == nullptr);    
}
#endif
