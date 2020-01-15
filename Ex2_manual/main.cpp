//
// Created by garridom on 14/1/2020.
//

#include <c++/4.8.3/iostream>
#include "Generator.h"
#include "LowPass.h"
#include "Display.h"

void test() {
    Pipe p1;
    //p1.pull();
    std::cout << p1.pull().getTypeAsString() << std::endl;

    Event e1("WARNING");
    p1.push(e1);
    std::cout << p1.pull().getTypeAsString() << std::endl;

    Pipe p2;
    Generator g(p2);
    std::cout << g.run() << std::endl;
    std::cout << "..." << std::endl;
    //std::cout << g.outputPipe_->pull().getTypeAsString() << std::endl;

    Pipe in, out;
    Event eIn("ADVISORY");
    in.push(eIn);
    LowPass lp(in, out);
    lp.run();
    std::cout << out.pull().getTypeAsString() << std::endl;
    std::cout << "..." << std::endl;

    eIn.setType("WARNING");
    in.push(eIn);
    LowPass lp2(in, out);
    lp2.run();
    std::cout << out.pull().getTypeAsString() << std::endl;
    std::cout << "If shows the same type, OK because the filter acts correctly";
    std::cout << std::endl;

    Display d(in);
    d.run();
}

void connect() { // Si es warning, no passa el filtre.
    Event e2("ADVISORY");

    Pipe p1;
    Pipe p2;

    Generator g(p1);
    g.run();
    std::cout << "Generator: " << p1.pull().getTypeAsString() << std::endl;

    LowPass lp(p1, p2);
    lp.run();
    std::cout << "LowPass out: " << p2.pull().getTypeAsString() << std::endl;

    Display d(p2);
    d.run();

    std::cout << "------------" << std::endl;
}

int main() {
    //test();
    while(1) connect();
}