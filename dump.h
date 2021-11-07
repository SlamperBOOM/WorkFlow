#pragma once
#include "Block.h"

class dump : public Block
{
public:
	virtual ~dump() override {}

	std::list<std::string> execute(const std::list<std::string>& text, const std::vector<std::string>& argv) override;

	BlockType GetType() override;
};

