//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_PIPE_H
#define INC_24_PIPE_H

#include "Event.h"

class Pipe {
private:
    Event event_;

public:
    Pipe();
    explicit Pipe(Event &e);
    ~Pipe() = default;
    void push(Event &e);
    Event pull();

};


#endif //INC_24_PIPE_H
