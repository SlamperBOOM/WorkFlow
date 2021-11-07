#pragma once
#include <vector>
#include <string>
#include <fstream>

class BlocksParser
{
public:
	static std::vector<std::pair<std::string, std::vector<std::string>>> GetBlocks(std::ifstream& input)
	{
		std::vector<std::pair<std::string, std::vector<std::string>>> blocks;
		std::string line;
		std::getline(input, line);
		while (std::getline(input, line))
		{
			if (line == "csed")
			{
				break;
			}
			size_t pos = line.find(' ');
			size_t index = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);
			pos = line.find(' ');
			line.erase(0, pos + 1);
			pos = line.find(' ');
			if (pos == std::string::npos)
			{
				pos = line.size();
			}
			std::string blockname = line.substr(0, pos);
			line.erase(0, pos + 1);
			std::vector<std::string> arguments;
			while (line.size() != 0)
			{
				pos = line.find(' ');
				if (pos == std::string::npos)
				{
					pos = line.size();
				}
				std::string arg = line.substr(0, pos);
				arguments.push_back(arg);
				line.erase(0, pos + 1);
			}
			if (blocks.size() < index)
			{
				blocks.resize(index);
			}
			std::pair<std::string, std::vector<std::string>> pair = std::make_pair(blockname, arguments);
			blocks.insert(blocks.cbegin() + index - 1, pair);
			for (size_t i = index; i < blocks.size() - 1; ++i)
			{
				blocks[i + 1] = blocks[i];
			}
			blocks.pop_back();
		}
		return blocks;
	}
};

