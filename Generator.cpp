//
// Created by garridom on 14/1/2020.
//

#include "Generator.h"


int Generator::run()
{
    int randNumber = rand() % 3;
    Event e = Event(static_cast<Event::Type>(randNumber));
    outputPipe->push(e);

    return randNumber;
}
