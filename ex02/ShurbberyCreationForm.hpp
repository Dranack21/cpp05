#pragma once

#include "Aform.hpp"

class ShrubberyCreationForm: public Aform
{
	private:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		void execute(Bureaucrat const & executor) const;
};