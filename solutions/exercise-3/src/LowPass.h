#ifndef LowPass_H
#define LowPass_H

#include "Event.h"

class Pipe;

class LowPass
{
public:
  LowPass(Pipe& in, Pipe& out, Event::Type ty = Event::Type::ADVISORY);
  int execute();

private:
  Pipe* input{};
  Pipe* output{};
  Event::Type filter_level{};
};


#endif  // LowPass_H