#pragma once
#include "WorkFlow.h"
#include "Block.h"
#include "BlocksParser.h"
#include "CommandsParser.h"
#include <fstream>
#include <exception>
#include <iostream>
#include <list>

class WorkFlowExe
{
public:
	void ExecuteWorkFlow(std::ifstream &input)
	{
		auto blocks = BlocksParser::GetBlocks(input);

		std::vector < std::pair < Block*, std::vector<std::string >>> blockobjects;
		for (size_t i = 0; i < blocks.size(); ++i)
		{
			blockobjects.resize(i + 1);
			if (blocks[i].first == "")
			{
				continue;
			}
			std::pair<Block*, std::vector<std::string>> pair = std::make_pair(WorkFlow::Instance().CreateBlock(blocks[i].first), blocks[i].second);
			blockobjects.insert(blockobjects.cbegin() + i, pair);
			for (size_t j = i + 1; j < blockobjects.size() - 2; ++j)
			{
				blockobjects[j] = blockobjects[j + 1];
			}
			blockobjects.pop_back();
		}

		std::vector<size_t> commands = CommandsParser::GetCommands(input);
		if (blockobjects[commands[0]].first->GetType() != BlockType::IN)
		{
			throw std::invalid_argument("Wrong type of block!").what();
		}
		for (size_t i = 1; i < commands.size() - 1; ++i)
		{
			if (blockobjects[commands[i]].first->GetType() != BlockType::INOUT)
			{
				throw std::invalid_argument("Wrong type of block!").what();
			}
		}
		if (blockobjects[commands[commands.size() - 1]].first->GetType() != BlockType::OUT)
		{
			throw std::invalid_argument("Wrong type of block!").what();
		}
		

		std::list<std::string> text;
		for (size_t i = 0; i < commands.size(); ++i)
		{
			text = blockobjects[commands[i]].first->execute(text, blockobjects[commands[i]].second);
		}
	}
};

