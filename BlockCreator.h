#pragma once

#include <iostream>
#include "IBlockCreator.h"
#include "WorkFlow.h"
#include "Exceptions/NoBlockEx.h"

class WorkFlow;

template<typename T>
class BlockCreator : public IBlockCreator
{
public:
	BlockCreator(const std::string& blockname)
	{
		try
		{
			WorkFlow::Instance().RegisterCreator(blockname, this);
		}
		catch (std::exception& ex)
		{
			std::cerr << "Error: " << ex.what() << std::endl;
			abort();
		}
	}

	virtual Block* CreateBlock() override
	{
		return new T();
	}
};

