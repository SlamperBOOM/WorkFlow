#pragma once
#include <exception>
#include <string>

class MultiplyMakersEx : public std::exception
{
public:
	MultiplyMakersEx() = default;

	const char* what() const noexcept 
	{
		return message.c_str();
	}

private:

	std::string message = "Multiply makers for given block!";
};

