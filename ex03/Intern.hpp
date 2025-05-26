#include "Bureaucrat.hpp"


class Intern
{
	private:
		Aform	*createShrubberyCreationForm(const std::string &target)const;
		Aform	*createRobotomyRequestForm(const std::string &target)const;
		Aform	*createPresidentialPardonForm(const std::string &target)const;
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern &operator=(const Intern& other);

		Aform *makeForm(const std::string &type, const std::string &target);

		class NoTypeFound : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

