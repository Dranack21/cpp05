#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
Aform("PresidentialPardonForm", 25, 5),
_target("default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
Aform("PrensidentialPardonForm", 25, 5),
_target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
Aform(other),
_target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		return *this;
	}
	return *this;
}


void PresidentialPardonForm::Be_Executed() const
{
	std::cout << this->_target << " Has been pardonned by Zaphod Beeblebrox" << std::endl;
}