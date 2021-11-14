#include <map>
#include "sort.h"

BlockCreator<sort> creator("sort");

std::list<std::string> sort::execute(const std::list<std::string>& text, const std::vector<std::string>& argv)
{
    if (argv.size() > 0)
    {
        throw std::exception("Too much agruments").what();
    }
    std::list<std::string> newtext;
    std::map<std::string, int> sorted;
    for (auto line : text)
    {
        sorted.emplace(line, 0);
    }
    for (auto line : sorted)
    {
        newtext.push_back(line.first);
    }
    return newtext;
}

BlockType sort::GetType()
{
    return BlockType::INOUT;
}
