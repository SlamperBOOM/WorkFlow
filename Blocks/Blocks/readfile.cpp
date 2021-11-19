#include <fstream>
#include <iostream>
#include <exception>
#include "readfile.h"

BlockCreator<readfile> creator("readfile");

std::list<std::string> readfile::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
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
	std::ifstream input(argv[0]);
	if (!input.is_open())
	{
		std::cerr << "Cannot open input file!" << std::endl;
		return text;
	}
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
