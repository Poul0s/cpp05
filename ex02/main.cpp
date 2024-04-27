/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:24:34 by psalame           #+#    #+#             */
/*   Updated: 2024/04/27 18:06:42 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test1(int &exit_code)
{
	// AForm	*form = new AForm(); // should not compile
	AForm					*shrubbery = new ShrubberyCreationForm("");
	RobotomyRequestForm		*robotomy = new RobotomyRequestForm("");
	PresidentialPardonForm	presidential ("");

	if (shrubbery->getName() != "ShrubberyCreationForm" || shrubbery->getRequireSign() != 145 || shrubbery->getRequireExec() != 137)
	{
		std::cerr << "ShrubberyCreationForm class has invalid properties." << std::endl
			<< shrubbery << std::endl;
		exit_code++;
	}
	if (robotomy->getName() != "RobotomyRequestForm" || robotomy->getRequireSign() != 72 || robotomy->getRequireExec() != 45)
	{
		std::cerr << "RobotomyRequestForm class has invalid properties." << std::endl
			<< robotomy << std::endl;
		exit_code++;
	}
	if (presidential.getName() != "PresidentialPardonForm" || presidential.getRequireSign() != 25 || presidential.getRequireExec() != 5)
	{
		std::cerr << "PresidentialPardonForm class has invalid properties." << std::endl
			<< presidential << std::endl;
		exit_code++;
	}

	delete shrubbery;
	delete robotomy;
}

void	test2(int &exit_code)
{
	ShrubberyCreationForm	*shrubbery = new ShrubberyCreationForm("");
	AForm					*shrubbery2 = shrubbery;
	AForm					*shrubbery3 = new ShrubberyCreationForm(*shrubbery);

	if (shrubbery2->getName() != "ShrubberyCreationForm" || shrubbery2->getRequireSign() != 145 || shrubbery2->getRequireExec() != 137)
	{
		std::cerr << "ShrubberyCreationForm copy has invalid properties." << std::endl
			<< shrubbery2 << std::endl;
		exit_code++;
	}
	if (shrubbery3->getName() != "ShrubberyCreationForm" || shrubbery3->getRequireSign() != 145 || shrubbery3->getRequireExec() != 137)
	{
		std::cerr << "ShrubberyCreationForm copy constructor has invalid properties." << std::endl
			<< shrubbery3 << std::endl;
		exit_code++;
	}

	delete shrubbery;
	delete shrubbery3;
}

void	test3(int &exit_code)
{
	Bureaucrat	bob ("Bob", 146);
	Bureaucrat	alice ("Alice", 144);
	Bureaucrat	boss ("Boss", 1);
	AForm		*form = new ShrubberyCreationForm("home");

	bob.signForm(*form);
	if (form->getSigned())
	{
		std::cerr << "Bob can sign form but he doesnt have right permissions." << std::endl;
		exit_code++;
	}
	alice.signForm(*form);
	if (!form->getSigned())
	{
		std::cerr << "Alice cant sign form but she have right permissions." << std::endl;
		exit_code++;
	}
	else
	{
		alice.executeForm(*form);
		boss.executeForm(*form);
	}
	delete form;
}

void	test4(int &exit_code)
{
	Bureaucrat	bob ("Bob", 146);
	Bureaucrat	alice ("Alice", 71);
	Bureaucrat	boss ("Boss", 1);
	AForm		*form = new RobotomyRequestForm("aaa");

	bob.signForm(*form);
	if (form->getSigned())
	{
		std::cerr << "Bob can sign form but he doesnt have right permissions." << std::endl;
		exit_code++;
	}
	alice.signForm(*form);
	if (!form->getSigned())
	{
		std::cerr << "Alice cant sign form but she have right permissions." << std::endl;
		exit_code++;
	}
	else
	{
		alice.executeForm(*form);
		boss.executeForm(*form);
		boss.executeForm(*form);
		boss.executeForm(*form);
	}
	delete form;
}

void	test5(int &exit_code)
{
	Bureaucrat	bob ("Bob", 146);
	Bureaucrat	alice ("Alice", 24);
	Bureaucrat	boss ("Boss", 1);
	AForm		*form = new PresidentialPardonForm("bbb");

	bob.signForm(*form);
	if (form->getSigned())
	{
		std::cerr << "Bob can sign form but he doesnt have right permissions." << std::endl;
		exit_code++;
	}
	alice.signForm(*form);
	if (!form->getSigned())
	{
		std::cerr << "Alice cant sign form but she have right permissions." << std::endl;
		exit_code++;
	}
	else
	{
		alice.executeForm(*form);
		boss.executeForm(*form);
	}
	delete form;
}

void	test_launcher(int &exit_code, void (*test_fct)(int &), int test_nb)
{
	int	prev_exit_code = exit_code;

	try
	{
		(*test_fct)(exit_code);
	}
	catch (std::exception &err)
	{
		exit_code += 1;
		std::cerr << "Unhandled exception in test : " << err.what() << std::endl;
	}
	if (exit_code != prev_exit_code)
		std::cout << "Test " << test_nb << " : failed." << std::endl;
	else
		std::cout << "Test " << test_nb << " : success." << std::endl;
}

int	main(void)
{
	int	exit_code = 0;
	int	test_nb = 1;

	test_launcher(exit_code, &test1, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test2, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test3, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test4, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test5, test_nb++);

	return exit_code;
}