#pragma once
#include "Block.h"

class sort : public Block
{
public:
	virtual ~sort() override {}

	std::list<std::string> execute(const std::list<std::string>& text, const std::vector<std::string>& argv) override;

	BlockType GetType() override;
};

