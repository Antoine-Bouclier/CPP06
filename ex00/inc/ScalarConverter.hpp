#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &src);
	public:
		static void convert(const std::string &input);
};

double	parseInput(const std::string &input, bool &impossible);
void	printChar(double d, bool impossible);
void	printInt(double d, bool impossible);
void	printFloat(double d, bool impossible);
void	printDouble(double d, bool impossible);
bool	isChar(const std::string &input);

#endif