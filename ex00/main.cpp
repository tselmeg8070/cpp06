#include "ScalarConverter.hpp"
#include "helpers.hpp"

int	main(int argc, char **argv)
{
	ScalarConverter converter;

	if (argc == 2)
	{
		try {
			converter.convert(argv[1]);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
