#pragma once
#include "WorkFlow.h"
#include "Block.h"
#include "BlocksParser.h"
#include <fstream>
#include <exception>
#include <iostream>
#include <list>
#include <memory>
#include "Exceptions/NoBlockEx.h"
#include "Exceptions/WrongTypeEx.h"

class WorkFlowExe
{
public:
	void ExecuteWorkFlow(std::ifstream &input)
	{
		//чтение блоков
		std::string line;
		std::getline(input, line);
		if (line != "desc")
		{
			return;
		}
		std::map<size_t, std::pair < std::string, std::vector<std::string >>> blocks;
		while (std::getline(input, line))
		{
			if (line == "csed")
			{
				break;
			}
			auto block = BlocksParser::GetBlock(line);
			blocks.insert(block);
		}
		//создание экземпл€ров блоков с аргументами
		std::map<size_t, std::pair <std::shared_ptr<Block>, std::vector<std::string >>> blockobjects;
		for (auto i : blocks)
		{
			std::shared_ptr<Block> b(WorkFlow::Instance().CreateBlock(i.second.first));
			auto pair1 = std::make_pair(b, i.second.second);
			auto pair = std::make_pair(i.first, pair1);
			blockobjects.insert(pair);
		}
		//чтение последовательности выполнени€ блоков
		std::vector<size_t> commands;
		std::getline(input, line);
		while (line.size() != 0)
		{
			size_t pos = line.find("->");
			if (pos == std::string::npos)
			{
				pos = line.size();
			}
			std::string command = line.substr(0, pos);
			size_t id = std::stoi(command);
			commands.push_back(id);
			line.erase(0, pos + 2);
		}
		BlockType b;
		if ((b = blockobjects[commands[0]].first->GetType()) != BlockType::IN)
		{
			std::string message = "expected IN block type, but got " + GetBlockTypeStr(b);
			throw WrongTypeEx(message);
		}
		for (size_t i = 1; i < commands.size() - 1; ++i)
		{
			if ((b = blockobjects[commands[i]].first->GetType()) != BlockType::INOUT)
			{
				std::string message = "expected INOUT block type, but got " + GetBlockTypeStr(b);
				throw WrongTypeEx(message);
			}
		}
		if (blockobjects[commands[commands.size() - 1]].first->GetType() != BlockType::OUT)
		{
			std::string message = "expected OUT block type, but got " + GetBlockTypeStr(b);
			throw WrongTypeEx(message);
		}
		//WorkFlow
		std::list<std::string> text;
		for (size_t i = 0; i < commands.size(); ++i)
		{
			text = blockobjects[commands[i]].first->execute(text, blockobjects[commands[i]].second);
		}
	}

private:
	std::string GetBlockTypeStr(BlockType b)
	{
		if (b == BlockType::IN) return "IN";
		else if (b == BlockType::INOUT) return "INOUT";
		else return "OUT";
	}
};

