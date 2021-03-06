#include "Generator.h"
#include "Event.h"
#include "Pipe.h"
#include <iostream>

using namespace std;

int Generator::execute()
{
  cout << "-----------------------------" << endl;
  cout << "Generator::execute:" << endl;
	int nr = (rand() % 3);
  switch(nr)
  {
  case 0:
    {
      output->push(Event{ Event::Type::ADVISORY });
      break;
    }
  case 1:
    {
      output->push(Event{ Event::Type::WARNING });
      break;
    }
  case 2:
    {
      output->push(Event{ Event::Type::CAUTION });
      break;
    }
  }
  return nr;
}

void Generator::executeMultipleEvents()
{
    cout << "-----------------------------" << endl;
    cout << "Generator::executeMultipleEvents:" << endl;
    int nr;



    for(int i = 0; i < Pipe::array_size; i++){
        nr = (rand() % 3);
        switch(nr)
        {
            case 0:
            {
                output->push(Event{ Event::Type::ADVISORY });
                break;
            }
            case 1:
            {
                output->push(Event{ Event::Type::WARNING });
                break;
            }
            case 2:
            {
                output->push(Event{ Event::Type::CAUTION });
                break;
            }
        }
    }
}
