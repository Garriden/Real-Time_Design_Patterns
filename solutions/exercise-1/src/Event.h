#ifndef EVENT_H
#define EVENT_H

// ---------------------------------------------------------------------------
// Events represent alarm conditions in the system.
//
class Event
{
public:
  enum class Type { WARNING, CAUTION, ADVISORY, UNKNOWN };
  
  Event() = default;
  Event(Type t);

  const char* typeAsString() const;
  Event::Type type() const;

private:
  Type eventType { Type::UNKNOWN };
};

#endif // EVENT_H

