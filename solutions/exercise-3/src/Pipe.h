#ifndef PIPE_H
#define PIPE_H

#include "Event.h"

#include <array>
// ---------------------------------------------------------------------------
// Array-Based-Event Pipe
//
class Pipe
{
public:
  Pipe() = default;
  void push(const Event& in);
  void pull(Event& out);

private:
  static constexpr unsigned array_size { 16 };
  std::array<Event, array_size> eventList{};
  unsigned next_in  { 0 };
  unsigned next_out { 0 };
};


#endif // PIPE_H