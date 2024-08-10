/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:53:17 by trimize           #+#    #+#             */
/*   Updated: 2024/08/10 18:35:13 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
	std::cout << std::endl;
	ShrubberyCreationForm shrubbery("home");
	b->signAForm(shrubbery);
	b->executeForm(shrubbery);
	RobotomyRequestForm r("Zucc");
	PresidentialPardonForm ppf("Joe Biden");
	b->signAForm(r);
	b->executeForm(r);
	std::cout << std::endl;
	b->setGrade(25);
	b->signAForm(ppf);
	b->executeForm(ppf);
	std::cout << std::endl;
	b->setGrade(5);
	b->signAForm(ppf);
	b->executeForm(ppf);
	std::cout << std::endl;
	Intern guy;
	AForm *f1 = guy.makeForm("shrubbery creation", "forest");
	AForm *f2 = guy.makeForm("robotomy request", "jerma");
	AForm *f3 = guy.makeForm("presidential pardon", "baby");
	AForm *f4 = guy.makeForm("Spacecraft donation", "me");
	std::cout << std::endl;
	b->signAForm(*f1);
	b->executeForm(*f1);
	std::cout << std::endl;
	b->signAForm(*f2);
	b->executeForm(*f2);
	std::cout << std::endl;
	b->signAForm(*f3);
	b->executeForm(*f3);
	delete b;
	delete f1;
	delete f2;
	delete f3;
	delete f4;
	return (0);
}