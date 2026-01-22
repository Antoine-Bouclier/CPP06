#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	private:
		
	public:
		virtual ~Base();
		virtual Base	*generate(void);
		virtual void	identify(Base* p);
		virtual void	identify(Base& p);
};

#endif