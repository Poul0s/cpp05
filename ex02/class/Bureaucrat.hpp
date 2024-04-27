/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:02:22 by psalame           #+#    #+#             */
/*   Updated: 2024/04/07 15:01:35 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"

class	AForm;
class	Bureaucrat
{
	public:
		// Constructor/destructor
		Bureaucrat(std::string name, short grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		// Operator overload
		Bureaucrat	&operator=(const Bureaucrat &copy);

		// Member functions
		std::string	getName(void) const;
		short		getGrade(void) const;
		void		promote(void);
		void		demote(void);
		void		signForm(AForm &form);
		void		executeForm(AForm const & form);

		// nested classes
		class	GradeTooHighException;
		class	GradeTooLowException;

	private:
		const std::string	_name;
		short				_grade;
};

std::ostream&	operator<<( std::ostream&output, const Bureaucrat& bureaucrat );

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

#endif