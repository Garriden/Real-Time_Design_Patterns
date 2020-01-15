//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_LOWPASS_H
#define INC_24_LOWPASS_H

#include "Pipe.h"

class LowPass {
private:
    Pipe *inputPipe_;
    Pipe *outputPipe_;
    int passValue_;

public:
    explicit LowPass(Pipe &input, Pipe &output);

    int run();
};


#endif //INC_24_LOWPASS_H
