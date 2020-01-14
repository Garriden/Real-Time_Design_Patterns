#include "Display.h"
#include "Event.h"
#include "Pipe.h"
#include <iostream>

using namespace std;


int Display::execute()
{
    cout << "-----------------------------" << endl;
    cout << "Display::execute:" << endl;
    Event event{};
    input->pull(event);
    if(event.type() != Event::Type::UNKNOWN) {
        cout << event.typeAsString() << endl;
    }
    return static_cast<int>(event.type());
}

#ifdef TDD
#include "doctest.h"

TEST_CASE("Empty pipe") {
    Pipe      pipe{};
    Display   d{ pipe };
    CHECK( d.execute() == 0);
}

TEST_CASE("Normal case") {
    Pipe      pipe{};
    Display   d{ pipe };
    pipe.push(Event{ Event::Type::WARNING });
    CHECK( d.execute() == 2);
}

#endif