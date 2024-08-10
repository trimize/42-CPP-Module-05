/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:53:17 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 15:12:31 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	int	i;
	Bureaucrat *b = new Bureaucrat("To", 170);

	std::cout << std::endl;
	i = 150;
	while (i < 152)
	{
		try
		{
			b->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		i++;
	}
	std::cout << std::endl;
	try
	{
		b->setGrade(-50);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	b->setGrade(5);
	i = 5;
	std::cout << std::endl;
	while (i > -5)
	{
		try
		{
			b->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		i--;
	}
	std::cout << b;
	delete b;
	return (0);
}