/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:24:34 by psalame           #+#    #+#             */
/*   Updated: 2024/04/03 19:37:55 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test1(int &exit_code)
{
	
}

void	test_launcher(int &exit_code, void (*test_fct)(int &))
{
	try
	{
		(*test_fct)(exit_code);
	}
	catch (std::exception &err)
	{
		exit_code += 1;
		std::cerr << "Unhandled exception in test : " << err.what() << std::endl;
	}
}

int	main(void)
{
	int	exit_code = 0;
	
	test_launcher(exit_code, &test1);
	std::cout << std::endl;
	test_launcher(exit_code, &test2);
	std::cout << std::endl;
	test_launcher(exit_code, &test3);
	std::cout << std::endl;
	test_launcher(exit_code, &test4);
	std::cout << std::endl;
	test_launcher(exit_code, &test5);
	std::cout << std::endl;
	test_launcher(exit_code, &test6);
	std::cout << std::endl;
	test_launcher(exit_code, &test7);

	return exit_code;
}