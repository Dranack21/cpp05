#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat; 
class Aform
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

		Aform();
		Aform(std::string str, int sign, int execute);
		Aform(const Aform &other);
		~Aform();
		Aform &operator=(const Aform &other);
		void	beSigned(Bureaucrat &Worker);
		
		virtual void execute(Bureaucrat const & executor) const = 0;
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

std::ostream	&operator<<(std::ostream &o, Aform *b);
