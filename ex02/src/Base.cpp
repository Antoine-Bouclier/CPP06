#include "Base.hpp"

Base::Base()
{
}

Base::Base(Base const &src)
{
	*this = src;
}

Base &Base::operator=(Base const &copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

Base::~Base()
{
}

Base	*Base::generate(void)
{

}
void	Base::identify(Base* p)
{

}
void	Base::identify(Base& p)
{

}