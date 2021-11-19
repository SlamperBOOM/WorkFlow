#include <fstream>
#include <iostream>
#include <exception>
#include "writefile.h"

static BlockCreator<writefile> creator("writefile");

std::list<std::string> writefile::execute(const std::list<std::string>& text, const std::vector<std::string>& argv) 
{
	if (argv.size() < 1)
	{
		throw std::invalid_argument("Not enough arguments");
	}
	if (argv.size() > 1)
	{
		throw std::invalid_argument("Too much arguments");
	}
	std::ofstream output(argv[0]);
	if (!output.is_open())
	{
		std::cerr << "Cannot open output file!" << std::endl;
		return text;
	}
	for (auto line : text)
	{
		output << line << std::endl;
	}
	output.close();
	output.close();
	return text;
}

BlockType writefile::GetType() 
{
	return BlockType::OUT;
}