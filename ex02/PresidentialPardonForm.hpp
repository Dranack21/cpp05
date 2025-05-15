#pragma once

#include "Aform.hpp"

class PresidentialPardonForm: public Aform
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		void execute(Bureaucrat const & executor) const;
};