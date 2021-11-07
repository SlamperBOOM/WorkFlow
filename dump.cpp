#include <fstream>
#include "dump.h"

BlockCreator<dump> creator("dump");

std::list<std::string> dump::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
{
    if (argv.size() < 1)
    {
        throw std::exception("Not enough agruments").what();
    }
    if (argv.size() > 1)
    {
        throw std::exception("Too much agruments").what();
    }
    std::ofstream dump(argv[0]);
    for (auto line : text)
    {
        dump << line << std::endl;
    }
    return text;
}

BlockType dump::GetType()
{
    return BlockType::INOUT;
}
