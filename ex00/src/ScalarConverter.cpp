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

std::array<std::string, 4> convertChar(const std::string &input)
{
	std::array<std::string, 4> value;

	if (!std::isprint(input[0]))
		value[0] = "impossible";
	else
		value[0] = std::string(1, input[0]);

	char c = input[0];

	value[1] = std::to_string(static_cast<int>(c));
	value[2] = std::to_string(static_cast<float>(c));
	value[3] = std::to_string(static_cast<double>(c));

	return value;
}

std::array<std::string, 4> convertInt(const int &input)
{
	std::array<std::string, 4> value;

	char	c = static_cast<char>(input);

	if (!std::isprint(c))
		value[0] = "impossible";
	else
		value[0] = std::string(1, c);

	value[1] = std::to_string(input);
	value[2] = std::to_string(static_cast<float>(input));
	value[3] = std::to_string(static_cast<double>(input));

	return value;
}

std::array<std::string, 4> convertFloat(const float &input)
{
	std::array<std::string, 4> value;

	char	c = static_cast<char>(input);

	if (!std::isprint(c))
		value[0] = "impossible";
	else
		value[0] = std::string(1, c);

	value[1] = std::to_string(static_cast<int>(input));
	value[2] = std::to_string(input).append("f");
	value[3] = std::to_string(static_cast<double>(input));

	return value;
}

std::array<std::string, 4> convertDouble(const double &input)
{
	std::array<std::string, 4> value;

	char	c = static_cast<char>(input);

	if (!std::isprint(c))
		value[0] = "impossible";
	else
		value[0] = std::string(1, c);

	value[1] = std::to_string(static_cast<int>(input));
	value[2] = std::to_string(static_cast<float>(input)).append("f");
	value[3] = std::to_string(input);

	return value;
}

static void printValue(const std::array<std::string, 4> &value)
{
	std::cout
		<< "char: " << value[0] << '\n'
		<< "int: " << value[1] << '\n'
		<< "float: " << value[2] << '\n'
		<< "double: " << value[3] <<
	std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	std::string	*value;
}