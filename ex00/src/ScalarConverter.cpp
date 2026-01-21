#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cerrno>
#include <limits>
#include <sstream>

template <typename T>
void	toString(T input, std::string &value)
{
	std::stringstream	ss;

	ss << input;
	value = ss.str();
}

bool isInt(const std::string &s)
{
	char *end;
	errno = 0;

	long v = std::strtol(s.c_str(), &end, 10);

	if (*end != '\0')
		return false;
	if (errno == ERANGE)
		return false;
	if (v < -2147483648 || v > 2147483647)
		return false;

	return true;
}

bool isFloat(const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;

	if (s[s.size() - 1] != 'f')
		return false;

	char *end;
	errno = 0;

	std::strtof(s.c_str(), &end);

	if (errno == ERANGE)
		return false;

	return end == s.c_str() + s.size() - 1;
}

bool isDouble(const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;

	char *end;
	errno = 0;

	std::strtod(s.c_str(), &end);

	if (errno == ERANGE)
		return false;

	return *end == '\0';
}


static bool	isChar(const std::string &input)
{
	return (input.length() == 1 && !std::isdigit(input[0]));
}

/* static bool	isSpecial(const std::string &input)
{
	return (input.compare("nan") == 0 || input.compare("nanf") == 0 ||
			input.compare("+inf") == 0 || input.compare("+inff") == 0 ||
			input.compare("-inf") == 0 || input.compare("-inff") == 0 ||
			input.compare("inf") == 0 || input.compare("inff") == 0);
} */

void convertChar(const std::string &input, std::string *value)
{
	if (!std::isprint(input[0]))
		value[0] = "impossible";
	else
		value[0] = std::string(1, input[0]);

	char c = input[0];

	toString(static_cast<int>(c), value[1]);
	toString(static_cast<float>(c), value[2]);
	toString(static_cast<double>(c), value[3]);
}

void convertInt(const int &input, std::string *value)
{
	char	c = static_cast<char>(input);

	if (!std::isprint(c))
		value[0] = "impossible";
	else
		value[0] = std::string(1, c);

	toString(input, value[1]);
	toString(static_cast<float>(input), value[2]);
	toString(static_cast<double>(input), value[3]);
}

void convertFloat(const float &input, std::string *value)
{
	char	c = static_cast<char>(input);

	if (!std::isprint(c))
		value[0] = "impossible";
	else
		value[0] = std::string(1, c);

	toString(static_cast<int>(input), value[1]);
	toString(input, value[2]);
	toString(static_cast<double>(input), value[3]);
}

void	convertDouble(const double &input, std::string *value)
{
	char	c = static_cast<char>(input);

	if (!std::isprint(c))
		value[0] = "impossible";
	else
		value[0] = std::string(1, c);

	toString(static_cast<int>(input), value[1]);
	toString(static_cast<float>(input), value[2]);
	toString(static_cast<double>(input), value[3]);
}

static void printValue(std::string *value)
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
	char	*end;
	std::string	*value = new std::string[4];

	if (isChar(input))
		convertChar(input, value);
	else if (isInt(input))
		convertInt(std::atoi(input.c_str()), value);
	else if (isFloat(input))
		convertFloat(std::strtof(input.c_str(), &end), value);
	else if (isDouble(input))
		convertDouble(std::strtod(input.c_str(), &end), value);

	printValue(value);

	delete[] value;
}