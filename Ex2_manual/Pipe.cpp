//
// Created by garridom on 14/1/2020.
//

#include "Pipe.h"

Pipe::Pipe() : event_(Event("HOLA"))
{

}

Pipe::Pipe(Event &e) : event_(e)
{

}

void Pipe::push(Event &e)
{
    event_ = e;
}

Event Pipe::pull()
{
    return event_;  // Destructs the event ?
}
