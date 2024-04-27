/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:42:53 by psalame           #+#    #+#             */
/*   Updated: 2024/04/27 22:01:40 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// constructors/destructors

Intern::Intern(void)
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}


// utils fcts
typedef AForm* (*formFct)(std::string &target);

static inline AForm	*createShrubbery(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static inline AForm	*createRobotomy(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static inline AForm	*createPresidential(std::string &target)
{
	return (new PresidentialPardonForm(target));
}


// member functions

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	formsName[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	formFct		formsConstructors[3] = {createShrubbery, createRobotomy, createPresidential};

	for (int i = 0; i < 3; i++)
	{
		if (form == formsName[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return (formsConstructors[i](target));
		}
	}
	std::cout << "Intern can't create " << form << "... He should only bring the coffee." << std::endl;
	return (NULL);
}