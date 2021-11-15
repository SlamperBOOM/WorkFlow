#pragma once
#include <vector>
#include <map>
#include <string>
#include <fstream>

class BlocksParser
{
public:
	static std::pair<size_t, std::pair < std::string, std::vector<std::string >>> GetBlock(std::string& line)
	{
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

		auto pair1 = std::make_pair(blockname, arguments);
		auto pair = std::make_pair(index, pair1);
		return pair;
	}
};

