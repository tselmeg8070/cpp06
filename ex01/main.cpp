#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data *data = new Data(2009);
	Serializer serializer;
	uintptr_t	ptr;

	std::cout << "Data ptr: " << data << std::endl;
	ptr = serializer.serialize(data);
	std::cout << "Serialized into: " << ptr << std::endl;
	std::cout << "Deserialized into: " << serializer.deserialize(ptr) << std::endl;
	delete data;
}
