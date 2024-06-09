
#include "Base.hpp"


Base::~Base(void){}


Base*	generate(void)
{
	srand(time(NULL));

	unsigned char n = rand() % 3;
	if (n == 0)
		return (new A());
	else if (n == 1)
		return (new B());
	return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "* Actual type object is A!" << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "* Actual type object is B!" << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "* Actual type object is C!" << std::endl;
		return ;
	}
	std::cout << "Can't identify the class!" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "& Actual type object is A!" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "& Actual type object is B!" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c ;
		std::cout << "& Actual type object is C!" << std::endl;
		return ;
	}
	catch (...) {}

	std::cout << "Can't identify the class!" << std::endl;
}

