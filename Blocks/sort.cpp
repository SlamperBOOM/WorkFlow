#include <map>
#include <exception>
#include "sort.h"

BlockCreator<sort> creator("sort");

std::list<std::string> sort::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
{
    if (argv.size() > 0)
    {
        throw std::invalid_argument("Too much agruments");
    }
    std::list<std::string> newtext = text;
    newtext.sort();
    return newtext;
}

BlockType sort::GetType()
{
    return BlockType::INOUT;
}
