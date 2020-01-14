#include "LowPass.h"

LowPass:LowPass() {

}

LowPass(Pipe& in, Pipe& out){
	this.pipe_input = in;
	this.pipe_output = out;
}

LowPass:~LowPass() {

}

int LowPass:run() {
	Event::Type value = this.pipe_input->pull();
	if ( value != nullptr && value < pass_value) {
		this.pipe_output->push(value)		
		return dynamic_cast<int>(value);
	}
	return -1;
		
	
}
