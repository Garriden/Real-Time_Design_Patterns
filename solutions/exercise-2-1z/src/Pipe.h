#ifndef PIPE_H
#define PIPE_H

#include "Event.h"

#include <optional>
// ---------------------------------------------------------------------------
// Single-Event Pipe
//
class Pipe
{
public:
  Pipe() = default;
  void push(const Event& in);
  std::optional<Event> pull();

private:
  Event event{};
};


#endif // PIPE_H