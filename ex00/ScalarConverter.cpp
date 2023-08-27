#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter &t)
{
	(void) t;
};

ScalarConverter::~ScalarConverter()
{};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &t)
{
	(void) t;
	return (*this);
}

void	ScalarConverter::printInt(int i)
{
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char: " << (i > 127 || i < 0 ? "impossible"
		: (std::isprint(i) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void	ScalarConverter::printChar(char c)
{
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void	ScalarConverter::printSpecial(const std::string &val)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << val << (val == "nanf" || val == "-inff" || val == "+inff" ? "" : "f") << std::endl;
	std::cout << "double: " << (val == "nanf" ? "nan" : val) << std::endl;
}

void 	ScalarConverter::printFloat(float f)
{
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<double>::min() && d <= std::numeric_limits<double>::max())
		std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
}

void 	ScalarConverter::printDouble(double d)
{
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<double>::min() && d <= std::numeric_limits<double>::max())
		std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string &val)
{
	if (val.size() == 0)
		throw ScalarConverter::InvalidInputException();
	else if (val.size() == 1)
	{
		if (std::isdigit(val[0]))
		{
			int d = std::atoi(val.c_str());
			ScalarConverter::printInt(d);
		}
		else
		{
			ScalarConverter::printChar(val[0]);
		}
	}
	else if (isSpecial(val))
		ScalarConverter::printSpecial(val);
	else
	{
		if (isFloat(val))
		{
			float f = std::atof(val.c_str());
			ScalarConverter::printFloat(f);
		}
		else if (isDouble(val))
		{
			char* endPtr;
			float d = std::strtod(val.c_str(), &endPtr);
			if (*endPtr == '\0') {
				ScalarConverter::printDouble(d);
			} else
				throw ScalarConverter::InvalidInputException();
		}
		else if (isInteger(val))
		{
			int d = std::atoi(val.c_str());
			ScalarConverter::printInt(d);
		}
		else
			throw ScalarConverter::InvalidInputException();
	}
}

const char *ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid input");
}
