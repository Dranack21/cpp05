#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "ShurbberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void)
{
	try 
	{
		std::string target = "Bob";

		Bureaucrat guy("Important guy", 5);
		Bureaucrat guy2("just a  guy", 150);
		PresidentialPardonForm papier(target);
		guy.signAform(papier);
		guy.executeForm(papier);
		papier.execute(guy2);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	
}