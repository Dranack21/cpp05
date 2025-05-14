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
			throw GradeTooHighException();
	}
	catch()
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
const std::string	Form::get_name()
{
	return(this->_name);
}
const int	Form::get_sign()
{
	return(this->_sign);
}
const int	Form::get_execute()
{
	return(this->_execute);
}
bool	Form::get_bool()
{
	return (this->_is_signed);
}

void Form::beSigned(Bureaucrat &Worker)
{
	if (this->_is_signed == true)
	{
		std::cout << "Form " << this->get_name() << " has alredy been signed" << std::endl;
		return ;
	}
	try
	{
		if (this->_sign <= Worker.getGrade())
			throw Form::GradeTooLowException();
		else
			this->_is_signed== true;
	}
	catch(Form::GradeTooHighException &e)
	{
		e.what();
	}
}




const char *Form::GradeTooHighException::what() const
{
	std::cout << "Form Grade Too High" << std::endl;
}

const char *Form::GradeTooLowException::what() const
{
	std::cout << "Form Grade Too Low" << std::endl;
}