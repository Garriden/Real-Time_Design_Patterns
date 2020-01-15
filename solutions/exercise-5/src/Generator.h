#ifndef GENERATOR_H
#define GENERATOR_H

class Pipe;

// ---------------------------------------------------------------------------
// Generator creates Events (randomly).  It does not receive
// any inputs; thus only has an output Pipe.
//
class Generator
{
public:
  Generator(Pipe& out) : output{ &out } {}
  int operator()();

private:
  Pipe* output;
};


#endif // GENERATOR_H
