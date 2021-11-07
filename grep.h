#pragma once
#include "Block.h"


class grep : public Block
{
public:
	virtual ~grep() override {}

	std::list<std::string> execute(const std::list<std::string>& text, const std::vector<std::string>& argv) override;

	BlockType GetType() override;
};

