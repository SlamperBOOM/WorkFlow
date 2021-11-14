#pragma once

#include "Block.h"
#include "IBlockCreator.h"
#include <string>
#include <map>
#include <memory>
#include "Exceptions/MultiplyMakersEx.h"
#include "Exceptions/NoBlockEx.h"


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
			throw MultiplyMakersEx();
		}
		makers[blockname] = maker;
	}

	Block* CreateBlock(const std::string& blockname)
	{
		auto i = makers.find(blockname);
		if (i == makers.end())
		{
			throw NoBlockEx();
		}
		IBlockCreator* creator = i->second;
		return creator->CreateBlock();
	}

private:
	WorkFlow() = default;
	WorkFlow(const WorkFlow& flow) = default;
	WorkFlow& operator=(const WorkFlow& flow) = default;

	std::map<const std::string, IBlockCreator*> makers;

};


