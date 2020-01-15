//
// Created by garridom on 14/1/2020.
//

#include "Pipe.h"

Event Pipe::pull()
{
    //return *event_;
}

void Pipe::push(Event& e)
{
    //event_ = &e;
}

Pipe::Pipe()
{
    //*event_ = Event{Event::Type::UNKNOWN};
}

Pipe::~Pipe()
{

}
