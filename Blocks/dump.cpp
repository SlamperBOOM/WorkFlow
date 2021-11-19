#include <fstream>
#include <exception>
#include "dump.h"

BlockCreator<dump> creator("dump");

std::list<std::string> dump::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
{
    if (argv.size() < 1)
    {
        throw std::invalid_argument("Not enough agruments");
    }
    if (argv.size() > 1)
    {
        throw std::invalid_argument("Too much agruments");
    }
    std::ofstream dump(argv[0]);
    if (!dump.is_open())
    {
        std::cerr << "Cannot open dump file!" << std::endl;
        return text;
    }
    for (auto line : text)
    {
        dump << line << std::endl;
    }
    dump.close();
    return text;
}

BlockType dump::GetType()
{
    return BlockType::INOUT;
}
