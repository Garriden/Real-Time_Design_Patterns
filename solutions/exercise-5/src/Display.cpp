#include "Display.h"
#include "Event.h"
#include "Pipe.h"
#include <iostream>

using namespace std;


int Display::operator()()
{
    cout << "-----------------------------" << endl;
    cout << "Display::execute:" << endl;
    std::unique_ptr<Event> event{};
    event = input->pull();
    if((event) && (event->type() != Event::Type::UNKNOWN)) {
        cout << event->typeAsString() << endl;
        return static_cast<int>(event->type());
    }
    return -1;
}
