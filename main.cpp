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
    if (!input.is_open())
    {
        std::cerr << "File cannot be opened!" << std::endl;
        return 0;
    }
    try
    {
        executor.ExecuteWorkFlow(input);
    }
    catch (std::exception &ex) 
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
