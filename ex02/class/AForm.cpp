/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:51:53 by psalame           #+#    #+#             */
/*   Updated: 2024/04/03 19:35:00 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// constructor/destructor
AForm::AForm(std::string name, short requireSign, short requireExec) : _name(name), _requireSign(requireSign), _requireExec(requireExec)
{
	if (requireSign < 1 || requireExec < 1)
		throw AForm::GradeTooHighException();
	if (requireSign > 150 || requireExec > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _requireSign(copy._requireSign), _requireExec(copy._requireExec)
{
	*this = copy;
}

AForm::~AForm(void)
{
}

// operator overload
AForm	&AForm::operator=(const AForm &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::ostream&	operator<<( std::ostream&output, const AForm& form )
{
	output << "Form " << form.getName() << " : " << std::endl;
	output << "\tsigned : " << (form.getSigned() ? "true" : "false") << std::endl;
	output << "\trequired grade for sign : " << form.getRequireSign() << std::endl;
	output << "\trequired grade for exec : " << form.getRequireExec();
	return (output);
}

// member functions
std::string	AForm::getName(void) const
{
	return (this->_name);
}

short	AForm::getRequireSign(void) const
{
	return (this->_requireSign);
}

short	AForm::getRequireExec(void) const
{
	return (this->_requireExec);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

void		AForm::beSigned(const Bureaucrat &author)
{
	if (author.getGrade() > this->_requireSign)
	{
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

// nested class
const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return "Form : grade too high.";
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return "Form : grade too low.";
}