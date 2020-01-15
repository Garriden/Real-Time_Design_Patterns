//
// Created by garridom on 15/1/2020.
//

#include "Display.h"

Display::Display(Pipe &input) : inputPipe_(&input)
{

}

int Display::run()
{
    int ret = 0;
    if(inputPipe_->pull().getType() == Event::Type::UNKNOWN) {
        ret = -1;
    }
    std::cout << "Display: " << inputPipe_->pull().getTypeAsString();
    std::cout << std::endl;
    return ret;
}
