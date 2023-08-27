#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include "Data.hpp"

class	Serializer {
	private:
		Serializer();
		Serializer(Serializer &t);
	public:
		~Serializer();
		Serializer & operator=(const Serializer &t);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
