/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:41:33 by psalame           #+#    #+#             */
/*   Updated: 2024/04/27 16:35:26 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

bool	RobotomyRequestForm::success = false;

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getRequireSign(), copy.getRequireExec())
{
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::ExecUnsignedException();
	if (executor.getGrade() > this->getRequireExec())
		throw AForm::GradeTooLowException();
	std::cout << "* Some drilling noises *" << std::endl;
	RobotomyRequestForm::success = !RobotomyRequestForm::success;
	if (RobotomyRequestForm::success)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "Failed to robotomize " << this->_target << std::endl;
}
