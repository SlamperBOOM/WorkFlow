#include <fstream>
#include "readfile.h"
#include "Block.h"

BlockCreator<readfile> creator("readfile");

std::list<std::string> readfile::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
{
	if (argv.size() < 1)
	{
		throw std::exception("Not enough arguments").what();
	}
	if (argv.size() > 1)
	{
		throw std::exception("Too much arguments").what();
	}
	std::list<std::string> newtext;
	std::ifstream input(argv[0]);
	std::string line;
	while (std::getline(input, line))
	{
		newtext.push_back(line);
	}
	input.close();
	return newtext;
}

BlockType readfile::GetType()
{
	return BlockType::IN;
}
