#include "Display.h"
#include "Event.h"
#include "Pipe.h"
#include <iostream>

#include <thread> 
#include <chrono>         // namespace chrono

using namespace std;
using namespace chrono;
using namespace chrono_literals;

int Display::operator()()
{
  // cout << "-----------------------------" << endl;
  // cout << "Display::execute:" << endl;
  std::unique_ptr<Event> event{};
  event = input->pull();
  if((event) && (event->type() != Event::Type::UNKNOWN)) {
      cout << event->typeAsString() << endl;
      // return static_cast<int>(event->type());
  }
  return 0;
}
