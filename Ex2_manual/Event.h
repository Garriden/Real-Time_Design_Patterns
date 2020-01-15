//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_EVENT_H
#define INC_24_EVENT_H

#include <c++/4.8.3/iostream>
#include <cstdio>
#include <cstring>

class Event {
public:
    enum class Type {WARNING, CAUTION, ADVISORY, UNKNOWN};
    Event();
    explicit Event(const char* c);
    ~Event();

    void setType(const char* c);
    Type getType();
    const char* getTypeAsString();
    int getIndexEnum(Type t);

private:
    Type type_;

};


#endif //INC_24_EVENT_H
