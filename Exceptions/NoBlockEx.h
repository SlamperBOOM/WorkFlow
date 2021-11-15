#pragma once
#include <exception>

class NoBlockEx : public std::exception
{
public:
	NoBlockEx() = default;

	const char* what() const noexcept
	{
		return message;
	}

private:

	const char* message = "No such block!";
};

