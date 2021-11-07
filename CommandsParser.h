#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class CommandsParser
{
public:
	static std::vector<size_t> GetCommands(std::ifstream& input)
	{
		std::vector<size_t> commands;
		std::string line;
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
			commands.push_back(id - 1);
			line.erase(0, pos + 2);
		}
		return commands;
	}
};

