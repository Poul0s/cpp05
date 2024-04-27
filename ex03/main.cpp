/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:24:34 by psalame           #+#    #+#             */
/*   Updated: 2024/04/27 22:01:23 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	test1(int &exit_code)
{
	Intern	slave1;
	Intern	slave2 (slave1);

	slave1 = slave2;
	(void)exit_code;
}

void	test2(int &exit_code)
{
	Intern	slave;
	AForm	*form;

	form = slave.makeForm("ShrubberyCreationForm", "home");
	if (form->getName() != "ShrubberyCreationForm")
		exit_code += 1;
	else if (form->getRequireSign() != 145)
		exit_code += 1;
	else if (form->getRequireExec() != 137)
		exit_code += 1;
	delete form;
}

void	test3(int &exit_code)
{
	Intern	slave;
	AForm	*form;

	form = slave.makeForm("RobotomyRequestForm", "aaa");
	if (form->getName() != "RobotomyRequestForm")
		exit_code += 1;
	else if (form->getRequireSign() != 72)
		exit_code += 1;
	else if (form->getRequireExec() != 45)
		exit_code += 1;
	delete form;
}

void	test4(int &exit_code)
{
	Intern	slave;
	AForm	*form;

	form = slave.makeForm("PresidentialPardonForm", "bbb");
	if (form->getName() != "PresidentialPardonForm")
		exit_code += 1;
	else if (form->getRequireSign() != 25)
		exit_code += 1;
	else if (form->getRequireExec() != 5)
		exit_code += 1;
	delete form;
}

void	test5(int &exit_code)
{
	Intern	slave;
	AForm	*form;

	form = slave.makeForm("aaaaaaaaaaaaaaaa", "ccc");
	if (form != NULL)
		exit_code += 1;
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