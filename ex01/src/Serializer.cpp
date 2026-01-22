#include "Serializer.hpp"

Serializer::Serializer()
{
}

/* -- Assignement operator -- */
Serializer::Serializer(Serializer const &copy)
{
	*this = copy;
}
Serializer &Serializer::operator=(Serializer const &src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{

}

Data*	Serializer::deserialize(uintptr_t raw)
{

}