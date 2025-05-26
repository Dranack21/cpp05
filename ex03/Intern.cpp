#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShurbberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Aform *Intern::makeForm(const std::string &type, const std::string &target)
{
	const std::string array[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

		
	Aform* (Intern::*formCreators[])(const std::string&) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	for (int i = 0; i != 3; i++)
	{
		if(type == array[i])
		{
			return((this->*formCreators[i])(target));
		}
	}
	throw Intern::NoTypeFound();
}

const char* Intern::NoTypeFound::what()const throw()
{
	return ("\033[1;31mIntern cannot create that type of form please refer to the array inside makeform function\n\033[0m");
}

Aform *Intern::createPresidentialPardonForm(const std::string &target)const
{
	return new PresidentialPardonForm(target);
}

Aform *Intern::createRobotomyRequestForm(const std::string &target)const
{
	return new RobotomyRequestForm(target);
}

Aform *Intern::createShrubberyCreationForm(const std::string &target)const
{
	return new ShrubberyCreationForm(target);
}