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
  Event event{};
  input->pull(event);
  if (static_cast<int>(event.type()) >= static_cast<int>(filter_level)) {
    output->push(event);
  }
  return static_cast<int>(event.type());
}
