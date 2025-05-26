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
		std::string	get_name()const;
		int			get_sign()const;
		int			get_execute()const;
		bool		get_bool()const;

		Aform();
		Aform(std::string str, int sign, int execute);
		Aform(const Aform &other);
		virtual ~Aform();
		Aform &operator=(const Aform &other);
		void	beSigned(Bureaucrat &Worker);
		
		void execute(Bureaucrat const & executor) const;
		virtual void Be_Executed()const = 0;
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
		class NotSigned: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NoExecute: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Aform *b);
