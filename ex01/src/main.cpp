#include "Serializer.hpp"

int	main(void)
{
	Data		ptr;
	uintptr_t	raw;

	ptr.s1 = "Hello world!";
	ptr.i = 12;

	raw = Serializer::serialize(&ptr);
	Data	*ptr2 = Serializer::deserialize(raw);
	
	std::cout << ptr2->i << std::endl;
	std::cout << ptr2->s1 << std::endl;

	std::cout << ptr.i << std::endl;
	std::cout << ptr.s1 << std::endl;
}