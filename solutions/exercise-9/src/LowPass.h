#ifndef LowPass_H
#define LowPass_H

#include "Event.h"
#include "Pipe.h"

class Generator;
class Display;
class Event;

class LowPass
{
public:
  LowPass(Generator& g, Display& d, Event::Type ty = Event::Type::ADVISORY);
  int operator()();
  void process(Event& ev);

private:
  Pipe input{};
  Generator* generator{};
  Display* display{};
  Event::Type filter_level;
};


#endif  // LowPass_H