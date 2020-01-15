#include "LowPass.h"
#include "Pipe.h"

#include <iostream>

using namespace std;

LowPass::LowPass(Pipe& in, Pipe& out, Event::Type ty) : 
input{ &in }, 
output{ &out },
filter_level { ty }
{

}


int LowPass::operator()()
{
  int rv { -1 };
  cout << "-----------------------------" << endl;
  cout << "LowPass::execute:" << endl;
  auto event{ input->pull() };
  if (event)  {
    if( static_cast<int>(event->type()) >= static_cast<int>(filter_level)) {
      rv = static_cast<int>(event->type());
      output->push(std::move(event));
    }
  }
  return rv;
}

#ifdef TDD
#include "doctest.h"
#include <memory>

TEST_CASE("Initial LowPass") {
    Pipe      in{};
    Pipe      out{};
    LowPass lp{in, out};
    auto rv = lp();
    CHECK( rv == -1);
}

TEST_CASE("LowPass push-pull") {
    Pipe      pipe1{};
    Pipe      pipe2{};
    LowPass lp{pipe1, pipe2};
    pipe1.push(std::make_unique<Event>(Event::Type::WARNING));
    auto rv = lp();
    CHECK( rv != -1);
    auto e{ pipe2.pull() };
    CHECK(e->type() == Event::Type::WARNING);
}

TEST_CASE("LowPass filter") {
    Pipe      pipe1{};
    Pipe      pipe2{};
    LowPass lp{pipe1, pipe2, Event::Type::CAUTION};
    pipe1.push(std::make_unique<Event>(Event::Type::WARNING));
    auto rv = lp();
    CHECK( rv == -1);
    auto e{ pipe2.pull() };
    CHECK(e == nullptr);
}

#endif
