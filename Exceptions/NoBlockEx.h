#pragma once
#include <exception>

class NoBlockEx : public std::exception
{
public:
	NoBlockEx() = default;

	const char* what() const noexcept
	{
		return message.c_str();
	}

private:

	std::string message = "No such block!";
};

