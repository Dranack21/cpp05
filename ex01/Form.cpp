#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form():
_name("default"),
_sign(10),
_execute(10),
_is_signed(false)
{
}
Form::Form(std::string str, int sign, int execute):
_name(str),
_sign(sign),
_execute(execute),
_is_signed(false)
{
	try
	{
		if (this->_sign > 150 || this->_execute > 150)
			throw GradeTooLowException();
		if (this->_sign < 0 || this->_execute < 0)
			throw GradeTooHighException();
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
}
Form::~Form()
{
}
Form::Form(const Form &other):
_name(other._name),
_sign(other._sign),
_execute(other._execute),
_is_signed(other._is_signed)
{
}
Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	return *this;
}
std::string	Form::get_name()
{
	return(this->_name);
}
int Form::get_sign()
{
	return(this->_sign);
}
int	Form::get_execute()
{
	return(this->_execute);
}
bool	Form::get_bool()
{
	return (this->_is_signed);
}

void Form::beSigned(Bureaucrat &Worker)
{
	if (this->get_bool() == true)
	{
		std::cout << "Form " << this->get_name() << " has alredy been signed" << std::endl;
		return ;
	}
	try
	{
		if (this->_sign <= Worker.getGrade())
			throw Form::GradeTooLowException();
		else
			this->_is_signed = true;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
}


const char *Form::GradeTooHighException::what() const throw()
{
	return("Form Grade Too High\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Form Grade Too Low\n");
}


std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Bureaucrat " << a->get_name() << " grade: " << a->get_sign() << std::endl;
	return (o);
}