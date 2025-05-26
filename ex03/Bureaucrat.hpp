#pragma once

#include <iostream>
#include "Aform.hpp"
#include <fstream>
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
		void 	signform(Aform &Aform);
		void	executeForm(Aform const & form);
	
		const std::string	getName()	const;
		int					getGrade()	const;
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