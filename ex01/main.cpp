#include "Bureaucrat.hpp"

int main()
{
	{
		Bureaucrat john("john", 1);
		std::cout << &john << std::endl;
		john.decrement_grade();
		std::cout << &john << std::endl;
		john.increment_grade();
		std::cout << &john << std::endl;
		john.increment_grade();
		std::cout << &john << std::endl;
		std::cout << std::endl << std::endl << std::endl ;
	}
	{
		Bureaucrat eve("eve", 15);
		std::cout << &eve << std::endl;
		eve.decrement_grade();
		std::cout << &eve << std::endl;
		std::cout << std::endl << std::endl << std::endl ;
	}
	{
		Bureaucrat bob("bob", 0);
		std::cout << &bob << std::endl;
		bob.decrement_grade();
		std::cout << &bob << std::endl;
		bob.increment_grade();
		std::cout << &bob << std::endl;
		std::cout << std::endl << std::endl << std::endl ;
	}
	{
		Bureaucrat aaaa("aaaaa", 151);
		std::cout << &aaaa << std::endl;
		aaaa.decrement_grade();
		std::cout << &aaaa << std::endl;
		aaaa.increment_grade();
		std::cout << &aaaa << std::endl;
	}
}

