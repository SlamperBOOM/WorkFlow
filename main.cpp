#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <exception>
#include "WorkFlowExe.h"

int main()
{
    WorkFlowExe executor;
    std::ifstream input("input1.txt");
	executor.ExecuteWorkFlow(input);
    std::cout << "WorkFlow executed successfully" << std::endl;
    return 0;
}
