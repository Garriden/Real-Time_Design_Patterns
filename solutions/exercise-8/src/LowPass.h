#ifndef LowPass_H
#define LowPass_H

#include "Event.h"
#include "Pipe.h"

class Display;
class Event;

class LowPass
{
public:
  LowPass(Display& d, Event::Type ty = Event::Type::ADVISORY);
  int operator()();
  void process(Event& ev);

private:
  Pipe input{};
  Display* display{};
  Event::Type filter_level;
};


#endif  // LowPass_H