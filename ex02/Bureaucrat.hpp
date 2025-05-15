#pragma once

#include <iostream>
#include "Aform.hpp"


class Aform; 
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
		void 	signAform(Aform &Aform);

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