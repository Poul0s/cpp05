/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:30:30 by psalame           #+#    #+#             */
/*   Updated: 2024/04/07 15:23:00 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm
{
	public:
		// constructor/destructor
		AForm(std::string name, short requireSign, short requireExec);
		AForm(const AForm &copy);
		virtual ~AForm(void);
		
		// operator overload
		virtual AForm	&operator=(const AForm &copy);

		// member functions
		std::string		getName(void) const;
		short			getRequireSign(void) const;
		short			getRequireExec(void) const;
		bool			getSigned(void) const;
		void			beSigned(const Bureaucrat &author);
		virtual	void	execute(Bureaucrat const & executor) const = 0;

		// nested class
		class	GradeTooHighException;
		class	GradeTooLowException;
		class	ExecUnsignedException;

	private:
		const std::string	_name;
		const short			_requireSign;
		const short			_requireExec;
		bool				_signed;
};

std::ostream&	operator<<( std::ostream&output, const AForm& Aform );

class AForm::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class AForm::ExecUnsignedException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

#endif
