#include "helpers.hpp"

bool	isSpecial(const std::string &val)
{
	return ( val == "nan" || val == "nanf"
			|| val == "-inff" || val =="+inff"
			||  val == "-inf" || val == "+inf");
}

bool	isFloat(const std::string &val)
{
	int	d = 0;
	for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.size(); i++)
	{
		if (d == 0 && std::isdigit(val[i]))
			d = 1;
		else if (d == 0 && !std::isdigit(val[i]))
			return (false);
		else if (d == 1 && val[i] == '.')
			d = 2;
		else if (d == 1 && val[i] != '.' && !std::isdigit(val[i]))
			return (false);
		else if (d == 2 && std::isdigit(val[i]))
			d = 3;
		else if ((d == 2 || d == 3) && !std::isdigit(val[i]) && val[i] != 'f')
			return (false);
		else if (d == 3 && val[i] == 'f')
			d = 4;
	}
	return (d == 4);
}

bool	isDouble(const std::string &val)
{
	int	d = 0;
	for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.size(); i++)
	{
		if (d == 0 && std::isdigit(val[i]))
			d = 1;
		else if (d == 0 && !std::isdigit(val[i]))
			return (false);
		else if (d == 1 && val[i] == '.')
			d = 2;
		else if (d == 1 && val[i] != '.' && !std::isdigit(val[i]))
			return (false);
		else if (d == 2 && std::isdigit(val[i]))
			d = 3;
		else if ((d == 2 || d == 3) && !std::isdigit(val[i]))
			return (false);
	}
	return (d == 3);
}

bool	isInteger(const std::string &val)
{
	for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.length(); i++)
	{
		if (!std::isdigit(val[i]))
			return (false);
	}
	return (true);
}
