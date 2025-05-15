#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string str, int i);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);

		void	decrement_grade();
		void	increment_grade();

		int	getGrade();
		const std::string getName();

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