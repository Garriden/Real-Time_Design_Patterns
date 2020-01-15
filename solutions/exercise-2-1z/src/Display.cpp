#include "Display.h"
#include "Event.h"
#include "Pipe.h"
#include <iostream>

using namespace std;


int Display::execute()
{
    cout << "-----------------------------" << endl;
    cout << "Display::execute:" << endl;
    auto event = input->pull();

    if(event) {
        cout << event.value().typeAsString() << endl;
    }
    // return static_cast<int>(event.type());
    return 0;
}
