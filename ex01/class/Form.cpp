/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:51:53 by psalame           #+#    #+#             */
/*   Updated: 2024/04/03 19:08:03 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// constructor/destructor
Form::Form(std::string name, short requireSign, short requireExec) : _name(name), _requireSign(requireSign), _requireExec(requireExec)
{
	this->_signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _requireSign(copy._requireSign), _requireExec(copy._requireExec)
{
	*this = copy;
}

Form::~Form(void)
{
}

// operator overload
Form	&Form::operator=(const Form &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::ostream&	operator<<( std::ostream&output, const Form& form )
{
	output << "Form " << form.getName() << " : " << std::endl;
	output << "\tsigned : " << (form.getSigned() ? "true" : "false") << std::endl;
	output << "\required grade for sign : " << form.getRequireSign() << std::endl;
	output << "\required grade for exec : " << form.getRequireExec();
	return (output);
}

// member functions
std::string	Form::getName(void) const
{
	return (this->_name);
}

short	Form::getRequireSign(void) const
{
	return (this->_requireSign);
}

short	Form::getRequireExec(void) const
{
	return (this->_requireExec);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

void		Form::beSigned(const Bureaucrat &author)
{
	if (author.getGrade() > this->_requireSign)
	{
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

// nested class
const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Form : grade too high.";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Form : grade too low.";
}