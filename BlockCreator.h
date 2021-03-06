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
		WorkFlow::Instance().RegisterCreator(blockname, this);
	}

	virtual Block* CreateBlock() override
	{
		return new T();
	}
};

