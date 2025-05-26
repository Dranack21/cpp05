#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): 
_name("default"), _grade(75)
{
}
Bureaucrat::Bureaucrat(std::string str, int i):
_name(str), _grade(i)
{
	if (this->_grade >= 151)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (this->_grade <= 0)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): 
_name(other._name),
_grade(other._grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

void Bureaucrat::signform(Aform &paper)
{
	try
	{
		paper.beSigned(*this);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}
const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::decrement_grade()
{
	std::cout << "Inside decrement function with " << this->getName() << std::endl;
	if (this->_grade + 1 >= 151)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->_grade = this->_grade + 1;
		std::cout << "New grade: " << this->_grade << std::endl;
	}
}

void Bureaucrat::increment_grade()
{
	std::cout << "Inside increment function with " << this->getName() << std::endl;
	if (this->_grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		this->_grade = this->_grade - 1;
		std::cout << "New grade: " << this->_grade << std::endl;
	}
}
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade Too Low\n");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade Too High\n");
}

void	Bureaucrat::executeForm(Aform const & form)
{
	if (form.get_sign() == false)
	{
		std::cout << this->_name << " Could not execute the form it is not signed yet" << std::endl;
		return ;
	}
	if (form.get_execute() < this->_grade)
	{
		std::cout << this->_name << " Cannot execute the form grade too low" << std::endl;
	}
	else
	{
		std::cout << "\033[35m" << std::endl  << this->_name << " Is about to execute form " << form.get_name() << std::endl << "\033[0m";
		form.Be_Executed();
		std::cout  << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << " sign grade: " << a->getGrade() << std::endl;
	return (o);
}