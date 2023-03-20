#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Num_Command : public Command {
public:
 Num_Command(Stack <int> & s, int num);
 void execute();

private:
 Stack <int> & s_;
 int num_;
};

#endif
