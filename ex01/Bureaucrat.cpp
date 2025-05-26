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
		this->_grade = 75;
		throw Bureaucrat::GradeTooLowException();
	}
	if (this->_grade <= 0)
	{
		this->_grade = 75;
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

void Bureaucrat::signForm(Form &paper)
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

int Bureaucrat::getGrade()
{
	return (this->_grade);
}
const std::string Bureaucrat::getName()
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "\033[32mBureaucrat " << a->getName() << " sign grade: " << a->getGrade() << "\033[0m" << std::endl;
	return (o);
}