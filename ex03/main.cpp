#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "Intern.hpp"
#include "ShurbberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{   
    try {
        std::cout << "===== TESTING INTERNS =====\n" << std::endl;

        Intern intern;

        std::cout << "--- Creating a shruberry from intern's makeForm ---" << std::endl;
        Aform* shrubberyForm = intern.makeForm("shrubbery creation", "Home");
        std::cout << shrubberyForm << std::endl;

         std::cout << "--- Creating a robotomy from intern's makeForm ---" << std::endl;
        Aform* robotomyForm = intern.makeForm("robotomy request", "Robot");
        std::cout << robotomyForm << std::endl;
        
         std::cout << "--- Creating a pardon from intern's makeForm ---" << std::endl;
        Aform* pardonForm = intern.makeForm("presidential pardon", "President");
        std::cout << pardonForm << std::endl;

        delete shrubberyForm;
        delete robotomyForm;
        delete pardonForm;


        std::cout << "===== NON-EXISTANT FORM TEST =====\n" << std::endl;

        Aform* nonExistantForm = intern.makeForm("non-existant form", "Target");
    
        std::cout << &nonExistantForm << std::endl; // <--- this line should not be reached
        delete nonExistantForm; // <--- same

    } catch (std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
    
    return 0;
}