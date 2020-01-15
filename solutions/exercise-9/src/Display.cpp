#include "Display.h"
#include "Event.h"
#include "Pipe.h"
#include <iostream>

#include <thread> 
#include <chrono>         // namespace chrono

using namespace std;
using namespace chrono;
using namespace chrono_literals;

void Display::show(Event& ev)
{
    input.push(make_unique<Event>(ev));
}

int Display::operator()()
{
  std::unique_ptr<Event> event{};
  event = input.pull();
  cout << event->typeAsString() << endl;
  return static_cast<int>(event->type());
}
