#include "following_functions.hpp"

int	main()
{
	Base *b = generate();

	identify(b);
	identify(*b);
	delete b;
}
