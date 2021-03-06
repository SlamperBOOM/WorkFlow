#include <exception>
#include "replace.h"

BlockCreator<replace> creator("replace");

std::list<std::string> replace::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
{
    if (argv.size() < 2)
    {
        throw std::invalid_argument("Not enough agruments");
    }
    if (argv.size() > 2)
    {
        throw std::invalid_argument("Too much agruments");
    }

    std::list<std::string> newtext;
    for (auto line : text)
    {
        size_t pos;
        while((pos = line.find(argv[0])) != std::string::npos)
        {
            line.replace(pos, argv[0].size(), argv[1]);
        }
        newtext.push_back(line);
    }
    return newtext;
}

BlockType replace::GetType()
{
    return BlockType::INOUT;
}
