#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		static double parseInput(const std::string &input, bool &impossible);
		static void printChar(double d, bool impossible);
		static void printInt(double d, bool impossible);
		static void printFloat(double d, bool impossible);
		static void printDouble(double d, bool impossible);

		static bool isChar(const std::string &input); 
	public:
		static void convert(const std::string &input);
};

#endif