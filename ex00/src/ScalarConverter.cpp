#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

bool	isChar(const std::string &input)
{
	return (input.length() == 1 && !std::isdigit(input[0]));
}

double	parseInput(const std::string &input, bool &impossible)
{
	double	d;

	impossible = false;

	if (isChar(input))
		return static_cast<double>(input[0]);

	char *end = NULL;
	d = std::strtod(input.c_str(), &end);

	if (end == input.c_str() || *end != '\0')
	{
		if (!(end && *end == 'f' && *(end + 1) == '\0'))
			impossible = true;
	}
	return d;
}

void	printChar(double d, bool impossible)
{
	std::cout << "char: ";
	if (impossible || std::isnan(d) || d < 0 || d > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(d) << "'\n";
}

void	printInt(double d, bool impossible)
{
	std::cout << "int: ";
	if (impossible || std::isnan(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";
}

void	printFloat(double d, bool impossible)
{
	std::cout << "float: ";
	if (impossible)
	{
		std::cout << "impossible\n";
		return;
	}

	float f = static_cast<float>(d);

	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff\n" : "-inff\n");
	else
	{
		std::cout << std::fixed << std::setprecision(
			(f == static_cast<int>(f)) ? 1 : 6
		);
		std::cout << f << "f\n";
	}
}

void	printDouble(double d, bool impossible)
{
	std::cout << "double: ";
	if (impossible)
	{
		std::cout << "impossible\n";
		return;
	}

	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf\n" : "-inf\n");
	else
	{
		std::cout << std::fixed << std::setprecision(
			(d == static_cast<int>(d)) ? 1 : 6
		);
		std::cout << d << "\n";
	}
}

void	ScalarConverter::convert(const std::string &input)
{
	bool	impossible;
	double	d = parseInput(input, impossible);

	printChar(d, impossible);
	printInt(d, impossible);
	printFloat(d, impossible);
	printDouble(d, impossible);
}