#include "Bureaucrat.hpp"
#include "Aform.hpp"

Aform::Aform():
_name("default"),
_sign(10),
_execute(10),
_is_signed(false)
{
}
Aform::Aform(std::string str, int sign, int execute):
_name(str),
_sign(sign),
_execute(execute),
_is_signed(false)
{
	
	if (this->_sign > 150 || this->_execute > 150)
		throw GradeTooLowException();
	if (this->_sign <= 0 || this->_execute <= 0)
		throw GradeTooHighException();
}
Aform::~Aform()
{
}
Aform::Aform(const Aform &other):
_name(other._name),
_sign(other._sign),
_execute(other._execute),
_is_signed(other._is_signed)
{
}
Aform &Aform::operator=(const Aform &other)
{
	if (this == &other)
		return *this;
	return *this;
}

std::string	Aform::get_name()const
{
	return(this->_name);
}
int Aform::get_sign()const
{
	return(this->_sign);
}
int	Aform::get_execute()const
{
	return(this->_execute);
}
bool	Aform::get_bool()const
{
	return (this->_is_signed);

}

void Aform::beSigned(Bureaucrat &Worker)
{
	if (this->get_bool() == true)
	{
		std::cout << "Aform " << this->get_name() << " has alredy been signed" << std::endl;
		return ;
	}
	if (this->_sign < Worker.getGrade())
	{
		std::cout << "Could not sign " << this->_name <<" because " << Worker.getName() << " grade is too low" << std::endl;
		throw Aform::GradeTooLowException();
	}
	else
	{
		this->_is_signed = true;
		std::cout << Worker.getName() << " signed " << this->_name << " Aform" << std::endl;
	}
}


const char *Aform::GradeTooHighException::what() const throw()
{
	return("\033[33mAform Grade Too High\033[0m\n");
}

const char *Aform::GradeTooLowException::what() const throw()
{
	return("\033[33mAform Grade Too Low\033[0m\n");
}

const char *Aform::NotSigned::what() const throw()
{
	return("\033[31mForm is not signed cannot execute\033[0m\n");
}

const char*Aform::NoExecute::what() const throw()
{
	return("\033[31mForm cannot be executed cause executor grade is too low\033[0m\n");
}

void	Aform::execute(Bureaucrat const &executor) const
{
	if (this->_sign == false)
		throw Aform::NotSigned();
	if (this->_execute < executor.getGrade())
		throw Aform::NoExecute();
	else
	{
		std::cout << executor.getName() << "is going to execute Form" << this->_name << std::endl;
		this->Be_Executed();
	}
}
std::ostream	&operator<<(std::ostream &o, Aform *a)
{
	o << "Form " << a->get_name() << " minimum required grade: " << a->get_sign() << std::endl;
	return (o);
}