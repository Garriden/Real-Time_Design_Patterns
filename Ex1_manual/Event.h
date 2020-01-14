//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_EVENT_H
#define INC_24_EVENT_H

#include <c++/4.8.3/iostream>
#include <cstdio>
#include <cstring>

class Event {
private:
    enum class Type {WARNING, CAUTION, ADVISORY, UNKNOWN};

    Type type_;

public:
    Event();
    explicit Event(const char* c);
    ~Event();

    void setType(const char* c);
    Type getType();
    const char* getTypeAsString();
};


#endif //INC_24_EVENT_H
