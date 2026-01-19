#include "ScalarConverter.hpp"

static bool	isChar(const std::string &input)
{
	return (input.length() == 1 && !std::isdigit(input[0]));
}

static bool	isSpecial(const std::string &input)
{
	return (input.compare("nan") == 0 || input.compare("nanf") == 0 ||
			input.compare("+inf") == 0 || input.compare("+inff") == 0 ||
			input.compare("-inf") == 0 || input.compare("-inff") == 0 ||
			input.compare("inf") == 0 || input.compare("inff") == 0);
}

void	ScalarConverter::convert(const std::string &input)
{

}