#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <array>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter(/* args */);
		~ScalarConverter();
	public:
		static void convert(const std::string &input);
};

#endif