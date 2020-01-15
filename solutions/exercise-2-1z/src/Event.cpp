#include "Event.h"

Event::Event(Event::Type t) : 
  eventType{ t } 
{
}


namespace
{
  const char* eventTypeStrings[] =
  {
    "UNKNOWN",
    "ADVISORY",
    "WARNING",
    "CAUTION",
  };

  const char* asString(Event::Type type)
  {
    return eventTypeStrings[static_cast<unsigned>(type)];
  }
}


const char* Event::typeAsString() const
{
  return asString(eventType);
}


Event::Type Event::type() const
{
  return eventType;
}

bool Event::operator==(const Event& rhs)
{
 return this->eventType == rhs.eventType;
}
bool Event::operator!=(const Event& rhs)
{
  return !operator==(rhs);
}

#ifdef TDD
#include "doctest.h"

TEST_CASE("Default Constructor") {
  Event e { };
  SUBCASE("As Type") {
    CHECK(e.type() == Event::Type::UNKNOWN);
  }
  SUBCASE("As String") {
    CHECK(e.typeAsString() == "UNKNOWN");
  }
}

TEST_CASE("WARNING Constructor") {
  Event e { Event::Type::WARNING };
  SUBCASE("As Type") {
    CHECK(e.type() == Event::Type::WARNING);
  }
  SUBCASE("As String") {
    CHECK(e.typeAsString() == "WARNING");
  }
}

TEST_CASE("CAUTION Constructor") {
  Event e { Event::Type::CAUTION };
  SUBCASE("As Type") {
    CHECK(e.type() == Event::Type::CAUTION);
  }
  SUBCASE("As String") {
    CHECK(e.typeAsString() == "CAUTION");
  }
}

TEST_CASE("ADVISORY Constructor") {
  Event e { Event::Type::ADVISORY };
  SUBCASE("As Type") {
    CHECK(e.type() == Event::Type::ADVISORY);
  }
  SUBCASE("As String") {
    CHECK(e.typeAsString() == "ADVISORY");
  }
}

#endif
