#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat john("john", 75);
			std::cout << &john << std::endl;
			john.decrement_grade();
			std::cout << &john << std::endl;
			john.increment_grade();
			std::cout << &john << std::endl;
			john.increment_grade();
			std::cout << &john << std::endl;
			std::cout << std::endl << std::endl << std::endl ;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what();
		}
	}
	{
		try
		{
			Bureaucrat eve("eve", 150);
			std::cout << &eve << std::endl;
			eve.increment_grade();
			std::cout << &eve << std::endl;
			eve.decrement_grade();
			std::cout << &eve << std::endl;
			eve.decrement_grade();
			std::cout << &eve << std::endl;
			std::cout << "I will never be printed" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what();
		}
	}
	{
		try
		{
			std::cout << std::endl << std::endl << std::endl ;
			Bureaucrat bob("bob", 0);
			std::cout << &bob << std::endl;
			bob.decrement_grade();
			std::cout << &bob << std::endl;
			bob.increment_grade();
			std::cout << &bob << std::endl;
			std::cout << std::endl << std::endl << std::endl ;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what();
		}
	}
}

