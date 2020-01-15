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

int LowPass::execute()
{
  cout << "-----------------------------" << endl;
  cout << "LowPass::execute:" << endl;
  Event event{};
  input->pull(event);
  // cout << event.typeAsString() << endl;

  if (static_cast<int>(event.type()) >= static_cast<int>(filter_level)) {
    output->push(event);
    // cout << event.typeAsString() << endl;
  }
  return static_cast<int>(event.type());
}

#ifdef TDD
#include "doctest.h"

TEST_CASE("Empty pipe") {
    Pipe      ipipe{};
    Pipe      opipe{};
    LowPass   lp{ ipipe, opipe };
    CHECK( lp.execute() == 0);
}

TEST_CASE("Normal case") {
    Pipe      ipipe{};
    Pipe      opipe{};
    LowPass   lp{ ipipe, opipe };
    ipipe.push(Event{ Event::Type::WARNING });
    CHECK( lp.execute() == 2);
}

#endif
