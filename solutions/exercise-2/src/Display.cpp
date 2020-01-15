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
