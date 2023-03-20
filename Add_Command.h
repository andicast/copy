#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Add_Command : public Command {
public:
 Add_Command(Stack <int> & s);
 void execute(void); 

private:
 Stack <int> & s_;
};

#endif
