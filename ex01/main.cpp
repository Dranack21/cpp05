#include "Bureaucrat.hpp"


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat intern("Intern john", 850);
	Bureaucrat guy("Important guy", 2);
	Form papier("Important Paper", 850, 20);
	std::cout << &intern;
	std::cout << &papier;
	intern.signForm(papier);
	return (0);
}