/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:41:33 by psalame           #+#    #+#             */
/*   Updated: 2024/04/27 17:03:35 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getRequireSign(), copy.getRequireExec())
{
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::ExecUnsignedException();
	if (executor.getGrade() > this->getRequireExec())
		throw AForm::GradeTooLowException();
	
	std::ofstream	file_to;
	file_to.open((this->_target + "_shrubbery").c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!file_to.is_open())
		throw ShrubberyCreationForm::CannotExecuteException(strerror(errno));
	file_to << "       _-_" << std::endl
			<< "    /~~   ~~\\" << std::endl
			<< " /~~         ~~\\" << std::endl
			<< "{               }" << std::endl
			<< " \\  _-     -_  /" << std::endl
			<< "   ~  \\\\ //  ~" << std::endl
			<< "_- -   | | _- _" << std::endl
			<< "  _ -  | |   -_" << std::endl
			<< "      // \\\\" << std::endl;
	file_to.close();
}


ShrubberyCreationForm::CannotExecuteException::~CannotExecuteException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
}

ShrubberyCreationForm::CannotExecuteException::CannotExecuteException(char *str) : _errStr(std::string("Cannot execute shrubbery creation form: ") + str)
{
}

const char	*ShrubberyCreationForm::CannotExecuteException::what(void) const throw()
{
	// std::string	res = "Cannot execute shrubbery creation form: ";
	// res += this->_errStr;
	// res += ".";
	return this->_errStr.c_str();
	// return ("aaaa");
}
