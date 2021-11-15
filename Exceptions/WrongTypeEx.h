#pragma once
#include <exception>

class WrongTypeEx : public std::exception
{
public:
	WrongTypeEx() = default;

	const char* what() const noexcept
	{
		return message;
	}

private:

	const char* message = "Wrong type of block in WorkFlow!";
};