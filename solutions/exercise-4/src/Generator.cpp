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
  cout << nr << endl;

  switch(nr)
  {
  case 0:
    {
      output->push(std::make_unique<Event>( Event::Type::ADVISORY ));
      break;
    }
  case 1:
  {
      output->push(std::make_unique<Event>( Event::Type::WARNING ));
      break;
    }

  case 2:
    {
      output->push(std::make_unique<Event>( Event::Type::CAUTION ));
      break;
    }


  }
  return nr;
}
