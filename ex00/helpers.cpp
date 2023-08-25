#include "ScalarConverter.hpp"

bool	isSpecial(const std::string &val)
{
	return ( val == "nan" || val == "nanf"
			|| val == "-inff" || val =="+inff"
			||  val == "-inf" || val == "+inf");
}
