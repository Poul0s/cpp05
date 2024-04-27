/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:37:02 by psalame           #+#    #+#             */
/*   Updated: 2024/04/27 17:04:00 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// constructor/destructor
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		// operator overload
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);

		// member functions
		void	execute(Bureaucrat const &executor) const;

		// nested class
		class	CannotExecuteException;
	
	private:
		std::string	_target;
};

class ShrubberyCreationForm::CannotExecuteException : public std::exception
{
	private:
		std::string	_errStr;
		
	public:
		~CannotExecuteException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
		CannotExecuteException(char *str);
		virtual const char	*what(void) const throw();

};

#endif