#pragma once

class Block;

class IBlockCreator
{
public:
	virtual Block* CreateBlock() = 0;

	virtual ~IBlockCreator() {};
};
