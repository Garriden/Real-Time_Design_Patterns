#ifndef EVENT_H
#define EVENT_H

// ---------------------------------------------------------------------------
// Events represent alarm conditions in the system.
//
class Event
{
public:
  enum class Type { UNKNOWN, ADVISORY, WARNING, CAUTION };
  
  Event() = default;
  Event(Type t);

  const char* typeAsString() const;
  Event::Type type() const;

  bool operator==(const Event& rhs);
  bool operator!=(const Event& rhs);
  
private:
  Type eventType { Type::UNKNOWN };
};

#endif // EVENT_H

