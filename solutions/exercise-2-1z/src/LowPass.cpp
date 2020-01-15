#include "LowPass.h"
#include "Pipe.h"

#include <iostream>

using namespace std;

LowPass::LowPass(Pipe& in, Pipe& out, Event::Type ty) : 
input{ &in }, 
output{ &out },
filter_level { ty }
{

}


int LowPass::execute()
{
  cout << "-----------------------------" << endl;
  cout << "LowPass::execute:" << endl;
  auto event = input->pull();
  if(event) 
  {  
    if (static_cast<int>(event.value().type()) >= static_cast<int>(filter_level)) {
        output->push(event.value());
    }
  }
  // return static_cast<int>(event.type());
  return 0;
}
