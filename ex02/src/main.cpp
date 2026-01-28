#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(time(NULL));
		seeded = true;
	}

	int r = std::rand() % 3;

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error!" << std::endl;
}
void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e)
	{}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e)
	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e)
	{}
}

int main(void)
{
	srand(time(NULL));

	Base *p1 = generate();
	Base *p2 = generate();
	Base *p3 = generate();

	identify(p1);
	identify(*p1);

	identify(p2);
	identify(*p2);

	identify(p3);
	identify(*p3);

	delete p1;
	delete p2;
	delete p3;
	return 0;
}
