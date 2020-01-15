#ifndef DISPLAY_H
#define DISPLAY_H

class Pipe;

// ---------------------------------------------------------------------------
// A Display class displays the Events it receives.  It does not
// have any outputs, therefore is simply a Sink-type Filter.
//
class Display
{
public:
  Display(Pipe& in) : input{ &in } {}
  int execute();

private:
  Pipe* input;
};



#endif // DISPLAY_H