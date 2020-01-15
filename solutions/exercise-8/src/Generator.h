#ifndef GENERATOR_H
#define GENERATOR_H

class LowPass;

class Generator
{
public:
  Generator(LowPass& out) : lowpass{ &out } {}
  int operator()();

private:
  LowPass* lowpass;
};


#endif // GENERATOR_H
