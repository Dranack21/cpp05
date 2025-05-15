#pragma once

#include <iostream>
#include "Form.hpp"


class Form; 
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string str, int i);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);


		void	decrement_grade();
		void	increment_grade();
		void 	signForm(Form &Form);

		const std::string	getName();
		int					getGrade();
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};


std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);