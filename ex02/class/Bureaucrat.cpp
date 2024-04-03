/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:55:35 by psalame           #+#    #+#             */
/*   Updated: 2024/04/03 19:20:46 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor/destructor
Bureaucrat::Bureaucrat(std::string name, short grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
}


// Operator overload
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy._grade;
	return (*this);
}

std::ostream&	operator<<( std::ostream&output, const Bureaucrat& bureaucrat )
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (output);
}


// Member functions
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

short		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::promote(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::demote(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void		Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() 
			<< " because " << err.what() << "." << std::endl;
	}
}


// Class Exceptions

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Cannot set grade to bureaucrat, grade is too high (< 1).";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Cannot set grade to bureaucrat, grade is too low (> 150).";
}
