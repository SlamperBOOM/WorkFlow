#pragma once
#include "WorkFlow.h"
#include "Block.h"
#include "BlocksParser.h"
#include <fstream>
#include <exception>
#include <iostream>
#include <list>
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
		std::map<size_t, std::pair <Block *, std::vector<std::string >>> blockobjects;
		for (auto i : blocks)
		{
			std::pair <Block*, std::vector<std::string >> pair1;
			try 
			{
				pair1 = std::make_pair(WorkFlow::Instance().CreateBlock(i.second.first), i.second.second);
			}
			catch(std::exception &ex)
			{
				std::cerr << "Error: " << ex.what() << std::endl;
				for (auto k : blockobjects)
				{
					delete k.second.first;
				}
				return;
			}
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
		try 
		{
			if (blockobjects[commands[0]].first->GetType() != BlockType::IN)
			{
				throw WrongTypeEx();
			}
			for (size_t i = 1; i < commands.size() - 1; ++i)
			{
				if (blockobjects[commands[i]].first->GetType() != BlockType::INOUT)
				{
					throw WrongTypeEx();
				}
			}
			if (blockobjects[commands[commands.size() - 1]].first->GetType() != BlockType::OUT)
			{
				throw WrongTypeEx();
			}
		}
		catch (std::exception& ex)
		{
			std::cerr << "Error: " << ex.what() << std::endl;
			for (auto k : blockobjects)
			{
				delete k.second.first;
			}
			return;
		}
		//WorkFlow
		std::list<std::string> text;
		for (size_t i = 0; i < commands.size(); ++i)
		{
			try 
			{
				text = blockobjects[commands[i]].first->execute(text, blockobjects[commands[i]].second);
			}
			catch (std::exception& ex)
			{
				std::cerr << "Error: " << ex.what() << std::endl;
				for (auto k : blockobjects)
				{
					delete k.second.first;
				}
				return;
			}
		}

		for (auto i : blockobjects)
		{
			delete i.second.first;
		}
	}
};

