#include "ShurbberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
Aform("ShurbberyCreationForm", 145, 137),
_target("default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
Aform("ShurbberyCreationForm", 145, 137),
_target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
Aform(other),
_target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		return *this;
	}
	return *this;
}

void ShrubberyCreationForm::Be_Executed() const
{
	std::string full_target; 
	full_target = this->_target + "_shrubbery";
	std::ofstream output(full_target.c_str());
	if (!output.is_open())
	{
		std::cerr << "Could Not Open Shruberry File" << std::endl;
		return;
	}

	output <<"                                            .\n"
"                                              .         ;  \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                    :         ;                   :;%;'     .,   \n"
"           ,.        %;     %;            ;        %;'    ,;\n"	
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'   \n"
"                        `@%.  `;@%.      ;@@%;         \n"
"                          `@%%. `@%%    ;@@%;        \n"
"                            ;@%. :@%%  %@@%;       \n"
"                              %@bd%%%bd%%:;     \n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '         \n"
"                                %@@@o%;:(.,'         \n"
"                            `.. %@@@o%::;         \n"
"                               `)@@@o%::;         \n"
"                                %@@(o)::;        \n"
"                               .%@@@@%::;         \n"
"                               ;%@@@@%::;.          \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,..    \n";
	output.close();
}
