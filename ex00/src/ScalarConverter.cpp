#include "ScalarConverter.hpp"

static bool	isChar(const std::string &input)
{
	return (input.length() == 1 && !std::isdigit(input[0]));
}

static bool	isSpecial(const std::string &input)
{
	return (input.compare("nan") || input.compare("nanf") ||
			input.compare("+inf") || input.compare("+inff") ||
			input.compare("-inf") || input.compare("-inff") ||
			input.compare("inf") || input.compare("inff"));
}

void	ScalarConverter::convert(const std::string &input)
{

}