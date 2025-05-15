#include "Bureaucrat.hpp"


#include "Bureaucrat.hpp"
#include "Aform.hpp"

int main(void)
{
	try 
	{
		Bureaucrat guy("Important guy", 2);
		Bureaucrat intern("Intern john", 1800);
		Aform papier("Important Paper", 149, 20);
		std::cout << &intern;
		std::cout << &papier;
		intern.signAform(papier);
		guy.signAform(papier);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	
}