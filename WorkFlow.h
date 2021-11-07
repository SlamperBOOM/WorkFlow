#pragma once

#include "Block.h"
#include "IBlockCreator.h"
#include <string>
#include <map>

class WorkFlow
{
public:
	static WorkFlow& Instance()
	{
		static WorkFlow factory;
		return factory;
	}

	void RegisterCreator(const std::string& blockname, IBlockCreator* maker)
	{
		if (makers.find(blockname) != makers.end())
		{
			throw new std::exception("Myltiply makers for given key");
		}
		makers[blockname] = maker;
	}

	Block* CreateBlock(const std::string& blockname)
	{
		auto i = makers.find(blockname);
		if (i == makers.end())
		{
			throw std::exception("No such block");
		}
		IBlockCreator* creator = i->second;
		return creator->CreateBlock();
	}

private:
	WorkFlow() = default;

	std::map<const std::string, IBlockCreator*> makers;

};


