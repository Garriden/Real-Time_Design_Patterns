//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_GENERATOR_H
#define INC_24_GENERATOR_H

#include "Pipe.h"

class Generator {
private:
    Pipe *outputPipe_;

public:
    explicit Generator(Pipe &p);
    ~Generator() = default;
    int run();

};


#endif //INC_24_GENERATOR_H
