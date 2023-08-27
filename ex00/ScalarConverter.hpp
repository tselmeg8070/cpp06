#ifndef SCALAR_CONVERTOR_HPP
# define SCALAR_CONVERTOR_HPP
# include <string>
# include <cstdlib>
# include <cctype>
# include <limits>
# include <stdexcept>
# include <iostream>
# include <cmath>
# include <iomanip>
# include "helpers.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &t);
	public:
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter &t);

		static void printInt(int i);
		static void printChar(char c);
		static void printSpecial(const std::string &val);
		static void printFloat(float f);
		static void printDouble(double d);
		static void convert(const std::string &val);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
