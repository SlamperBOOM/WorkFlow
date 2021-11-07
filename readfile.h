#pragma once

#include <fstream>
#include "Block.h"


class readfile : public Block
{
public:
	virtual ~readfile() override{}

	std::list<std::string> execute(const std::list<std::string>& text, const std::vector<std::string>& argv) override;

	BlockType GetType() override;
};
