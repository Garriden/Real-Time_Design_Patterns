#ifndef PIPE_H
#define PIPE_H

#include "Event.h"

#include <array>
#include <c++/4.8.3/bits/unique_ptr.h>

// ---------------------------------------------------------------------------
// Array-Based-Event Pipe
//
class Pipe
{
public:
  Pipe() = default;
  int push(std::unique_ptr<Event> in);
  void pull(std::unique_ptr<Event> out);
  static constexpr unsigned array_size { 16 };


private:
  std::array<std::unique_ptr<Event>, array_size>  eventList{};
  unsigned next_in  { 0 };
  unsigned next_out { 0 };
};


#endif // PIPE_H