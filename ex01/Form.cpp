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
	
	if (this->_sign > 150 || this->_execute > 150)
		throw GradeTooLowException();
	if (this->_sign < 1 || this->_execute < 1)
		throw GradeTooHighException();
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
	if (this->_sign < Worker.getGrade())
	{
		std::cout << "\033[31mCould not sign " << this->_name <<" because " << Worker.getName() << " grade is too low about to throw Form to low as asked in subject\033[0m" << std::endl;
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_is_signed = true;
		std::cout << "\033[37m" << Worker.getName() << " signed " << this->_name << " form\033[0m" << std::endl;
	}
}


const char *Form::GradeTooHighException::what() const throw()
{
	return("\033[33mForm Grade Too High\033[0m\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("\033[36mForm Grade Too Low\033[0m\n");
}


std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "\033[33mForm " << a->get_name() << " minimum required grade: " << a->get_sign() << "\033[0m" << std::endl;
	return (o);
}