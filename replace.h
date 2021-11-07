#pragma once
#include "Block.h"

class replace : public Block
{
public:
	virtual ~replace() override {}

	std::list<std::string> execute(const std::list<std::string>& text, const std::vector<std::string>& argv) override;

	BlockType GetType() override;
};

