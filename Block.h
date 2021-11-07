#pragma once
 
#include <list>
#include <string>
#include <vector>
#include "BlockCreator.h"

enum class BlockType {
	IN,
	OUT,
	INOUT
};

class Block
{
public:
	virtual std::list<std::string> execute(const std::list<std::string>& text, const std::vector<std::string>& agrv) = 0;

	virtual BlockType GetType() = 0;

	virtual ~Block() {};
};
