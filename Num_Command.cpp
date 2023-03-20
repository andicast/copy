#include "Num_Command.h"
#include <iostream>

Num_Command::Num_Command(Stack <int> & s, int num)
:s_(s),
 num_(num)
{
}

void Num_Command::execute() {
 s_.push (num_);
}
 
