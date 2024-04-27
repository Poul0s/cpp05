/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:31:48 by psalame           #+#    #+#             */
/*   Updated: 2024/04/27 21:58:40 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &copy);

		AForm	*makeForm(std::string form, std::string target);
};

#endif