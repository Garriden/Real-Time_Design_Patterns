//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_LOWPASS_H
#define INC_24_LOWPASS_H

#include "Pipe.h"

class LowPass {

public:
    LowPass();
    LowPass(Pipe& in, Pipe& out);

    ~LowPass();
    Event::Type pass_value;
    int run();

private:
    Pipe* pipe_input;
    Pipe* pipe_output;
};

#endif //INC_24_LOWPASS_H
