#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <exception>
#include "WorkFlowExe.h"

int main()
{
    WorkFlowExe executor;
    std::ifstream input("input.txt");
    if (!input.is_open())
    {
        std::cerr << "File cannot be opened!" << std::endl;
        return 0;
    }
	executor.ExecuteWorkFlow(input);
    return 0;
}
