/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:51:38 by psalame           #+#    #+#             */
/*   Updated: 2024/04/03 16:21:38 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

void	test1(int &exit_code)
{
	try
	{
		Bureaucrat bureaucrat1 = Bureaucrat("aaaa", 0);
		exit_code += 1;
	}
	catch (Bureaucrat::GradeTooHighException &err)
	{
		std::cout << "Test 1 success." << std::endl;
	}
}

void	test2(int &exit_code)
{
	try
	{
		Bureaucrat bureaucrat1 = Bureaucrat("aaaa", 151);
		exit_code += 1;
	}
	catch (Bureaucrat::GradeTooLowException &err)
	{
		std::cout << "Test 2 success." << std::endl;
	}
}

void	test3(int &exit_code)
{
	Bureaucrat bureaucrat1 = Bureaucrat("b1", 125);
	Bureaucrat bureaucrat2 (bureaucrat1);

	if (bureaucrat1.getGrade() != bureaucrat2.getGrade())
	{
		std::cerr << "Test 3 failed : bad constructor copy (grade)." << std::endl;
		exit_code += 1;
	}
	else if (bureaucrat1.getName() != bureaucrat2.getName())
	{
		std::cerr << "Test 3 failed : bad constructor copy (name)." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "Test 3 success." << std::endl;
}

void	test4(int &exit_code)
{
	Bureaucrat bureaucrat1 = Bureaucrat("b1", 125);
	Bureaucrat bureaucrat2 = Bureaucrat("b2", 126);

	bureaucrat2 = bureaucrat1;
	if (bureaucrat1.getGrade() != 125 || bureaucrat1.getGrade() != 125)
	{
		std::cerr << "Test 4 failed : bad grade copy (grade)." << std::endl;
		exit_code += 1;
	}
	else if (bureaucrat1.getName() != "b1" || bureaucrat2.getName() != "b2")
	{
		std::cerr << "Test 4 failed : bad grade copy (name)." << std::endl;
		exit_code += 1;
	}
	else
	{
		std::cout << "Test 4 success." << std::endl;
	}
}

void	test5(int &exit_code)
{
	Bureaucrat bureaucrat1 = Bureaucrat("b1", 2);
	bureaucrat1.promote();
	if (bureaucrat1.getGrade() != 1)
	{
		std::cerr << "Test 5 failed : bad grade promote." << std::endl;
		exit_code += 1;
	}
	else
	{
		try
		{
			bureaucrat1.promote();
			std::cerr << "Test 5 failed : no exception promote too high." << std::endl;
			exit_code += 1;
		}
		catch (Bureaucrat::GradeTooHighException &err)
		{
			std::cout << "Test 5 success." << std::endl;
		}
	}
}

void	test6(int &exit_code)
{
	Bureaucrat bureaucrat1 = Bureaucrat("b1", 149);
	bureaucrat1.demote();
	if (bureaucrat1.getGrade() != 150)
	{
		std::cerr << "Test 6 failed : bad grade demote." << std::endl;
		exit_code += 1;
	}
	else
	{
		try
		{
			bureaucrat1.demote();
			std::cerr << "Test 6 failed : no exception demote too low." << std::endl;
			exit_code += 1;
		}
		catch (Bureaucrat::GradeTooLowException &err)
		{
			std::cout << "Test 6 success." << std::endl;
		}
	}
}

void	test7(int &exit_code)
{
	std::string			name = "b1";
	short				grade = 5;
	Bureaucrat			bureaucrat (name, grade);
	
	std::stringstream	expected_stream;
	expected_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	std::string			expectedStr = expected_stream.str();
	
	std::stringstream	str_stream;
	str_stream << bureaucrat;
	std::string			resStr = str_stream.str();

	std::cout << "res: " << resStr << std::endl;
	if (resStr != expectedStr)
	{
		std::cout << "expected: " << expectedStr << std::endl;
		std::cerr << "Test 7 failed." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "Test 7 success." << std::endl;
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