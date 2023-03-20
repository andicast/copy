#include "Stack_Command_Factory.h"

Stack_Command_Factory::Stack_Command_Factory(Stack <int> & s) 
:stack_(s)
{
}

Num_Command * Stack_Command_Factory::create_num_command(int number){
 return new Num_Command(stack_, number);
}

Add_Command * Stack_Command_Factory::create_add_command(void) {
 return new Add_Command(stack_);
}
