//
// Created by garridom on 14/1/2020.
//

#include <c++/4.8.3/iostream>
#include "Event.h"

Event::Event()
{
    std::cout << "Constructor" << std::endl;
}

Event::Event(Event::Type t)
{
    std::cout << "Constructor" << std::endl;
    type_ = t;
}

Event::~Event()
{
    std::cout << "Destructor" << std::endl;
}

Event::Type Event::type() const
{
    return type_;
}


const char *Event::typeAsString() const
{
    if (type_ == Type::WARNING) return "WARNING";
    else if (type_ == Type::CAUTION) return "CAUTION";
    else if (type_ == Type::ADVISORY) return "ADVISORY";

    return "UNDEFINED";
}


