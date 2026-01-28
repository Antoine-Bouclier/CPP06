#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static void convert(const std::string &input);
};

#endif