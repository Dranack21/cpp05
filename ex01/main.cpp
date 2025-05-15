#include "Bureaucrat.hpp"


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try 
	{
		Bureaucrat guy("Important guy", 2);
		Bureaucrat intern("Intern john", 1800);
		Form papier("Important Paper", 149, 20);
		std::cout << &intern;
		std::cout << &papier;
		intern.signForm(papier);
		guy.signForm(papier);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	
}