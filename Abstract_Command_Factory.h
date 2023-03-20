#ifndef _ABSTRACT_COMMAND_FACTORY_H_
#define _ABSTRACT_COMMAND_FACTORY_H_

#include "Num_Command.h"
#include "Add_Command.h"

class Abstract_Command_Factory {
public:
 virtual Num_Command * create_num_command(int number) = 0;
 virtual Add_Command * create_add_command(void) = 0;
};

#endif
