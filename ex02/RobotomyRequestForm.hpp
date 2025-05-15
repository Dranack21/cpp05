#pragma once

#include "Aform.hpp"

class RobotomyRequestForm: public Aform
{
	private:

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		void execute(Bureaucrat const & executor) const;
};