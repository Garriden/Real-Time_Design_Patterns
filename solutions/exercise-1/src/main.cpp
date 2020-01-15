#ifndef TDD     // DO NOT REMOVE

#include "Event.h"
#include <iostream>

using namespace std;

int main()
{
  Event e1{ };
  Event e2{ Event::Type::ADVISORY };
  
  cout << e1.typeAsString() << endl;
  cout << e2.typeAsString() << endl;
}


// DO NOT REMOVE
#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#endif