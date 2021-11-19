#include <exception>
#include "grep.h"

BlockCreator<grep> creator("grep");

std::list<std::string> grep::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
{
	if (argv.size() < 1)
	{
		throw std::invalid_argument("Not enough arguments").what();
	}
	if (argv.size() > 1)
	{
		throw std::invalid_argument("Too much arguments").what();
	}
	std::list<std::string> newtext;
	for (auto line : text)
	{
		if (line.find(argv[0]) != std::string::npos)
		{
			newtext.push_back(line);
		}
	}
	return newtext;
}

BlockType grep::GetType()
{
	return BlockType::INOUT;
}
