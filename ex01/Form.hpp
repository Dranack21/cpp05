#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		const int			_sign;
		const int 			_execute;
		bool				_is_signed;
	public:

		const std::string	get_name();
		const	int			get_sign();
		const	int			get_execute();
		bool				get_bool();

		Form();
		Form(std::string str, int sign, int execute);
		Form(const Form &other);
		~Form();
		Form &operator=(const Form &other);
		void	beSigned(Bureaucrat &Worker);
		
		class GradeTooHighException: std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: std::exception
		{
			public:
				const char* what() const throw();
		};
};
