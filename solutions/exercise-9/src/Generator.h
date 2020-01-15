#ifndef GENERATOR_H
#define GENERATOR_H


class LowPass;

#include "Event.h"

#include <memory>

class Generator
{
public:
  Generator() = default;
  std::unique_ptr<Event> operator()();
  std::unique_ptr<Event> generate_event();
};


#endif // GENERATOR_H
