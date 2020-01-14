//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_PIPE_H
#define INC_24_PIPE_H
#include "Event.h"

class Pipe {
    Pipe();
    ~Pipe();
public:
    void push(Event e);
    Event pull();

private:
    Event event_;
};


#endif //INC_24_PIPE_H
