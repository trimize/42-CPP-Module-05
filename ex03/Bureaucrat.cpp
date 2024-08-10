/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:10:37 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 17:38:11 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name) : name(name)
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	try
	{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << ", grade initialized to 150" << std::endl;
		this->setGrade(150);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << ", grade initialized to 150" << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(int grade) : name("default")
{
	try
	{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << ", grade initialized to 150" << std::endl;
		this->setGrade(150);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << ", grade initialized to 150" << std::endl;
		this->setGrade(150);
	}
	
}

Bureaucrat::Bureaucrat(void) : name("default"), grade(150)
{
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	*this = b;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this != &b)
		this->grade = b.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

void	Bureaucrat::signAForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(AForm::FormNotSigned& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *b)
{
	o << "Bureaucrat " << b->getName() << ", grade " << b->getGrade() << std::endl;
	return (o);
}
