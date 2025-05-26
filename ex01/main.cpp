#include "Bureaucrat.hpp"


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try 
	{
		Bureaucrat guy("Important guy", 2);
		Bureaucrat intern("Intern john", 150);
		Form papier("Important Paper", 20, 20);
		Form papier2("Important Paper2", 125, 20);
		std::cout << &guy;
		std::cout << &intern;
		std::cout << &papier;
		intern.signForm(papier);
		guy.signForm(papier);
		papier2.beSigned(intern);
		papier2.beSigned(guy);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	
}