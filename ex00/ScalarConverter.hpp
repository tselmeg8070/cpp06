#ifndef SCALAR_CONVERTOR_HPP
# define SCALAR_CONVERTOR_HPP
# include <string>
# include <cstdlib>
# include <cctype>
# include <limits>
# include <stdexcept>
# include <iostream>
# include <cmath>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter &t);
		~ScalarConverter();
		ScalarConverter & operator=(const ScalarConverter &t);

		static void printInt(int i);
		static void printChar(char c);
		static void printSpecial(const std::string &val);
		static void printFloat(float f);
		static void printDouble(double d);
		static void convert(const std::string &val);

		class NonPrintableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

bool	isSpecial(const std::string &val);

#endif
