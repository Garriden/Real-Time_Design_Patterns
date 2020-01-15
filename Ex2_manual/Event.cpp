//
// Created by garridom on 14/1/2020.
//

#include "Event.h"

Event::Event() : type_(Type::UNKNOWN)
{
    //std::cout << "Constructor" << std::endl;
}

Event::Event(const char* c) : type_()
{
    //std::cout << "Constructor" << std::endl;
    setType(c);
}

Event::~Event()
{
    //std::cout << "Destructor" << std::endl;
}

void Event::setType(const char *c)
{
    if(strcmp(c, "CAUTION") == 0) {
        type_ = Type::CAUTION;
    } else if(strcmp(c, "WARNING") == 0) {
        type_ = Type::WARNING;
    } else if(strcmp(c, "ADVISORY") == 0) {
        type_ = Type::ADVISORY;
    } else {
        type_ = Type::UNKNOWN;
    }
}

Event::Type Event::getType()
{
    return type_;
}

const char* Event::getTypeAsString()
{
    switch(type_)
    {
        case Type::CAUTION:
            return "CAUTION";
        case Type::WARNING:
            return "WARNING";
        case Type::ADVISORY:
            return "ADVISORY";
        default:
            return "UNKNOWN";
    }
}

int Event::getIndexEnum(Event::Type t)
{
    switch(t)
    {
        case Type::WARNING:
            return 0;
        case Type::CAUTION:
            return 1;
        case Type::ADVISORY:
            return 2;
        case Type::UNKNOWN:
            return -1;
    }
}
