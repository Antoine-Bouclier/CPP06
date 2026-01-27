#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	private:
		Base();
		Base(Base const &copy);
		Base	&operator=(Base const &src);
	public:
		virtual ~Base();
		virtual Base	*generate(void);
		virtual void	identify(Base* p);
		virtual void	identify(Base& p);
};

#endif