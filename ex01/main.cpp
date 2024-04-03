/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:19:30 by psalame           #+#    #+#             */
/*   Updated: 2024/04/03 19:01:52 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	test1(int &exit_code)
{
	try
	{
		Form form1 = Form("f1", -2, 2);
		exit_code += 1;
	}
	catch (Form::GradeTooHighException &err)
	{
		try
		{
			Form form2 = Form("f2", 2, -2);
			exit_code += 1;
			
		}
		catch (Form::GradeTooHighException &err)
		{
			Form form3 = Form("f3", 1, 1);
			std::cout << "Test 1 success." << std::endl;
		}
	}
}

void	test2(int &exit_code)
{
	try
	{
		Form form1 = Form("f1", 151, 2);
		exit_code += 1;
	}
	catch (Form::GradeTooLowException &err)
	{
		try
		{
			Form form2 = Form("f2", 2, 151);
			exit_code += 1;
			
		}
		catch (Form::GradeTooLowException &err)
		{
			Form form3 = Form("f3", 150, 150);
			std::cout << "Test 2 success." << std::endl;
		}
	}
}

void	test3(int &exit_code)
{
	Form form1 = Form("f1", 2, 2);
	Form form2 (form1);

	if (form1.getName() != form2.getName())
	{
		std::cerr << "Test 3 failed : bad constructor copy (name)." << std::endl;
		exit_code += 1;
	}
	else if (form1.getRequireSign() != form2.getRequireSign())
	{
		std::cerr << "Test 3 failed : bad constructor copy (require sign)." << std::endl;
		exit_code += 1;
	}
	else if (form1.getRequireExec() != form2.getRequireExec())
	{
		std::cerr << "Test 3 failed : bad constructor copy (require exec)." << std::endl;
		exit_code += 1;
	}
	else if (form1.getSigned() != form2.getSigned())
	{
		std::cerr << "Test 3 failed : bad constructor copy (signed)." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "Test 3 success." << std::endl;
}

void	test4(int &exit_code)
{
	Form form1 = Form("f1", 2, 2);
	Form form2 = Form("f2", 5, 5);

	form2 = form1;
	if (form1.getName() != "f1" || form2.getName() != "f2")
	{
		std::cerr << "Test 4 failed : bad copy (name)." << std::endl;
		exit_code += 1;
	}
	else if (form1.getRequireSign() != 2 || form1.getRequireSign() != 5)
	{
		std::cerr << "Test 4 failed : bad copy (require sign)." << std::endl;
		exit_code += 1;
	}
	else if (form1.getRequireExec() != 2 || form1.getRequireExec() != 5)
	{
		std::cerr << "Test 4 failed : bad copy (require exec)." << std::endl;
		exit_code += 1;
	}
	else if (form1.getSigned() != false || form1.getSigned() != false)
	{
		std::cerr << "Test 4 failed : bad copy (signed)." << std::endl;
		exit_code += 1;
	}
	else
	{
		std::cout << "Test 4 success." << std::endl;
	}
}

void	test5(int &exit_code)
{
	Bureaucrat	b1("b1", 5);
	Form		f1("f1", 5, 5);
	Form		f2("f2", 4, 4);
	
	f1.beSigned(b1);
	if (!f1.getSigned())
	{
		std::cerr << "Test 5 failed : signed isnt true." << std::endl;
		exit_code++;
	}
	else
	{
		try
		{
			f2.beSigned(f2);
			std::cerr << "Test 5 failed : bad sign permission." << std::endl;
			exit_code++;
		}
		catch (Form::GradeTooLowException &err)
		{
			if (f2.getSigned())
			{
				std::cerr << "Test 5 failed : signed is true." << std::endl;
				exit_code++;
			}
			else
				std::cout << "Test 5 success." << std::endl;
		}
	}
}

void	test6(int &exit_code)
{
	Bureaucrat	b1("b1", 5);
	Form		f1("f1", 5, 5);
	Form		f2("f2", 4, 4);

	b1.signForm(f1);
	if (!f1.getSigned())
	{
		std::cerr << "Test 6 failed : didnt signed f1." << std::endl;
		exit_code++;
	}
	else
	{
		b1.signForm(f2);
		if (f2.getSigned())
		{
			std::cerr << "Test 6 failed : signed f2." << std::endl;
			exit_code++;
		}
		else
			std::cout << "Test 6 success." << std::endl;
	}
}

void	test7(int &exit_code)
{
	Form		f1("f1", 5, 6);
	Bureaucrat	b1("b1", 5);

	std::stringstream	expected_str_stream;
	expected_str_stream << "Form f1 : " << std::endl;
	expected_str_stream << "\tsigned : false" << std::endl;
	expected_str_stream << "\required grade for sign : 5" << std::endl;
	expected_str_stream << "\required grade for exec : 6";
	std::string			expected_str = expected_str_stream.str();

	std::stringstream	current_str_stream;
	current_str_stream << f1;
	std::string			current_str = current_str_stream.str();

	std::cout << "res : " << current_str << std::endl;
	if (current_str != expected_str)
	{
		std::cout << "expected : " << expected_str_stream << std::endl;
		std::cerr << "Test 7 failed : bad operator '<<'" << std::endl;
		exit_code++;
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