#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
_target("default")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target):
_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
_target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		
	}
}