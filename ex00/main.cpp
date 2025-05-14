#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bob("bob", 159);
	Bureaucrat john("john", 1);
	Bureaucrat eve("eve", 15);
	john.decrement_grade(100);

	std::cout << &john << std::endl;
	john.increment_grade(10);
	std::cout << &john << std::endl;
	std::cout << &eve << std::endl;
	eve.decrement_grade(10);
	std::cout << &eve << std::endl;
}

