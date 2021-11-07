#include <fstream>
#include "writefile.h"
#include "Block.h"

static BlockCreator<writefile> creator("writefile");

std::list<std::string> writefile::execute(const std::list<std::string>& text, const std::vector<std::string>& argv) 
{
	if (argv.size() < 1)
	{
		throw std::exception("Not enough arguments").what();
	}
	if (argv.size() > 1)
	{
		throw std::exception("Too much arguments").what();
	}
	std::ofstream output(argv[0]);
	for (auto line : text)
	{
		output << line << std::endl;
	}
	output.close();
	return text;
}

BlockType writefile::GetType() 
{
	return BlockType::OUT;
}