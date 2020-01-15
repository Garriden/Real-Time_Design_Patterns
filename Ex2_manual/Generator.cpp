//
// Created by garridom on 14/1/2020.
//

#include "Generator.h"

Generator::Generator(Pipe &p) : outputPipe_(&p)
{

}

int Generator::run()
{
    int random = rand() % 3;
    Event e;
    switch (random)
    {
        case 0:
            e.setType("WARNING");
            break;
        case 1:
            e.setType("CAUTION");
            break;
        case 2:
            e.setType("ADVISORY");
            break;
        default:
            e.setType("UNKNOWN");
            break;
    }
    outputPipe_->push(e);

    return random;
}
