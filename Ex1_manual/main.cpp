//
// Created by garridom on 14/1/2020.
//

#include <c++/4.8.3/iostream>
#include "Event.h"

int main() {
    std::cout << "Hello World!" << std::endl;

    Event e1;
    Event e2("CAUTIO");
    Event e3("CAUTION");

    std::cout << e2.getTypeAsString() << std::endl;
    std::cout << e3.getTypeAsString() << std::endl;

}