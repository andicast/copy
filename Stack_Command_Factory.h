#ifndef _STACK_COMMAND_FACTORY_H_
#define _STACK_COMMAND_FACTORY_H_

#include "Abstract_Command_Factory.h"
#include "Stack.h"

class Stack_Command_Factory : public Abstract_Command_Factory {
public:
 Stack_Command_Factory(Stack <int> & s);
 Num_Command * create_num_command(int number);
 Add_Command * create_add_command(void);

private:
 Stack <int> & stack_; 
};

#endif
