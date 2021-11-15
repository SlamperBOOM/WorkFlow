#pragma once
#include <exception>

class MultiplyMakersEx : public std::exception
{
public:
	MultiplyMakersEx() = default;

	const char* what() const noexcept 
	{
		return message;
	}

private:

	const char* message = "Multiply makers for given block!";
};

