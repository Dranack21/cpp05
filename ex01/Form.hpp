#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat; 
class Form
{
	private:
		const std::string	_name;
		const int			_sign;
		const int 			_execute;
		bool				_is_signed;
	public:

		std::string	get_name();
		int			get_sign();
		int			get_execute();
		bool				get_bool();

		Form();
		Form(std::string str, int sign, int execute);
		Form(const Form &other);
		~Form();
		Form &operator=(const Form &other);
		void	beSigned(Bureaucrat &Worker);
		
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Form *b);
