#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():
Aform("RobotomyRequestForm", 72, 45),
_target("default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
Aform("RobotomyRequestForm", 72, 45),
_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
Aform(other),
_target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		return *this;
	}
	return *this;
}


void  RobotomyRequestForm::Be_Executed() const
{
	int i;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	i = rand();
	if (i%2 == 0)
		std::cout << this->_target << " Has been robotomized" << std::endl;
	else
		std::cout << this->_target << " Did not get robotomized" << std::endl;

}