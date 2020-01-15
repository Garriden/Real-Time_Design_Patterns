#ifndef DISPLAY_H
#define DISPLAY_H

#include "Pipe.h"
#include "Event.h"

class Display
{
public:
  Display() = default;
  int operator()();
  void show(Event& ev);
private:
  Pipe input{};
};



#endif // DISPLAY_H