#pragma once

#include <fstream>
#include "..\Block.h"


class writefile : public Block
{
public:
	virtual ~writefile() override{}

	std::list<std::string> execute(const std::list<std::string>& text, const std::vector<std::string>& argv) override;

	BlockType GetType() override;
};
