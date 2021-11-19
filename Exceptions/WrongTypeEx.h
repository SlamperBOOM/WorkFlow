#pragma once
#include <exception>

class WrongTypeEx : public std::exception
{
public:
	WrongTypeEx() = default;

	WrongTypeEx(std::string &mes)
	{
		message = mes.c_str();
	}

	const char* what() const noexcept
	{
		return message.c_str();
	}

private:

	std::string message = "Wrong type of block in WorkFlow!";
};