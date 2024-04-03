/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:30:30 by psalame           #+#    #+#             */
/*   Updated: 2024/04/03 19:35:36 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;
class	Form
{
	public:
		// constructor/destructor
		Form(std::string name, short requireSign, short requireExec);
		Form(const Form &copy);
		virtual ~Form(void);
		
		// operator overload
		Form	&operator=(const Form &copy);

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

	private:
		const std::string	_name;
		const short			_requireSign;
		const short			_requireExec;
		bool				_signed;
};

std::ostream&	operator<<( std::ostream&output, const Form& form );

class Form::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class Form::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

#endif
