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

		Bureaucrat guy("Important guy", 2);
		PresidentialPardonForm papier(target);
		guy.signAform(papier);
		guy.executeForm(papier);
		
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	
}