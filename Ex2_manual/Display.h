//
// Created by garridom on 15/1/2020.
//

#ifndef INC_24_DISPLAY_H
#define INC_24_DISPLAY_H

#include "Pipe.h"

class Display {
private:
    Pipe *inputPipe_;

public:
    explicit Display(Pipe &input);
    int run();
};


#endif //INC_24_DISPLAY_H
