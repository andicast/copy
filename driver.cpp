#include <iostream>
#include <sstream> //used for stringstream
#include "Array.h"
#include "Stack.h"
#include "Command.h"
#include "Add_Command.h"
#include "Num_Command.h"
#include "Stack_Command_Factory.h"

int main() {
 Stack<int> result;
 Array<Command *> postfix;

 std::string infix = "5 3 +";
 std::istringstream ss(infix);
 std::string token;
 
 Stack_Command_Factory * factory = new Stack_Command_Factory(result);

 while(getline(ss, token, ' ')) {
  if(isdigit(token[0]) == true) {
   int number = stoi(token);
   Command * command1 = factory->create_num_command(number);
   command1->execute();
  }
  else if(token == "+") {
   Command * command2 = factory->create_add_command();
   command2->execute();
  }
 }
  
 int solution = result.top();
 std::cout<<"Answer: "<< solution << std::endl;

 return 0;
}
