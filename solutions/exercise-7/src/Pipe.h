#ifndef PIPE_H
#define PIPE_H

#include "Event.h"

#include <array>
#include <memory>
#include <mutex>
#include <condition_variable>

// ---------------------------------------------------------------------------
// Single-Event Pipe
//
class Pipe
{
public:
  Pipe() = default;
  void push(std::unique_ptr<Event> in);
  std::unique_ptr<Event> pull();

private:
  static constexpr unsigned array_size { 16 };
  std::array<std::unique_ptr<Event>, array_size> eventList{};
  unsigned next_in  { 0 };
  unsigned next_out { 0 };

  std::mutex mtx;
  std::condition_variable while_empty;
};


#endif // PIPE_H