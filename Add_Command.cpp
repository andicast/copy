#include "Add_Command.h" 

Add_Command::Add_Command(Stack <int> & s)
:s_(s)
{
}

void Add_Command::execute(void) {
	int num2 = s_.pop();
	int num1 = s_.pop();
	s_.push(num1 + num2);
}
