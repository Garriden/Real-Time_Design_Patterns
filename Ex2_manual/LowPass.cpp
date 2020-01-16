//
// Created by garridom on 14/1/2020.
//

#include "LowPass.h"

LowPass::LowPass(Pipe &input, Pipe &output)
: inputPipe_(&input), outputPipe_(&output), passValue_(1)
{

}

int LowPass::run()
{
    int ret = -1;
    Event e = inputPipe_->pull();
    if(e.getType() != Event::Type::UNKNOWN) {
        if(static_cast<int>(e.getType()) >= passValue_) {
            outputPipe_->push(e);
        }
        ret = 0;
    }
    return ret;
}
