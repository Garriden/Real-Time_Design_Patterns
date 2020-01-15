#ifndef PIPE_H
#define PIPE_H

#include "Event.h"

// ---------------------------------------------------------------------------
// Single-Event Pipe
//
class Pipe
{
public:
  Pipe() = default;
  void push(const Event& in);
  void pull(Event& out);

private:
  Event event{};
};


#endif // PIPE_H