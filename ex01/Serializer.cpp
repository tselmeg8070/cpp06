#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer &t)
{
	(void) t;
}

Serializer::~Serializer()
{}

Serializer & Serializer::operator=(const Serializer &t)
{
	(void) t;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
