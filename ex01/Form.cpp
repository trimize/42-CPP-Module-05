/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:32:15 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 17:23:27 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name) : name(name), grade_sign(150), grade_exec(150)
{
	this->setSignature(false);
}

Form::Form(const int grade_sign, const int grade_exec) : name("default"), grade_sign(grade_sign), grade_exec(grade_exec)
{
	this->setSignature(false);
	if (grade_sign > 150)
		throw Form::GradeTooLowException();
	else if (grade_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_exec > 150)
		throw Form::GradeTooLowException();
	else if (grade_exec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const std::string name, const int grade_sign, const int grade_exec) : name(name), grade_sign(grade_sign), grade_exec(grade_exec)
{
	this->setSignature(false);
	if (grade_sign > 150)
		throw Form::GradeTooLowException();
	else if (grade_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_exec > 150)
		throw Form::GradeTooLowException();
	else if (grade_exec < 1)
		throw Form::GradeTooHighException();
}

Form::Form() : name("default"), grade_sign(150), grade_exec(150)
{
	this->setSignature(false);
}

Form::Form(const Form &f) : signature(f.getSignature()), grade_sign(f.getGradeSign()), grade_exec(f.getGradeExec())
{
	*this = f;
}

Form& Form::operator=(const Form &f)
{
	if (this != &f)
		setSignature(f.getSignature());
	return (*this);
}

Form::~Form()
{
	
}

std::string	Form::getName() const
{
	return (this->name);
}

bool		Form::getSignature() const
{
	return (this->signature);
}

int		Form::getGradeSign() const
{
	return (this->grade_sign);
}

int		Form::getGradeExec() const
{
	return (this->grade_exec);
}

void		Form::setSignature(bool b)
{
	this->signature = b;
}

void		Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeSign())
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because ";
		throw Form::GradeTooLowException();
		std::cout << std::endl;
	}
	else
	{
		this->setSignature(true);
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade too low");
}

std::ostream	&operator<<(std::ostream &o, Form *b)
{
	
	if (b->getSignature())
		o << "Form " << b->getName() << ", grade to sign " << b->getGradeSign() << ", grade to execute " << b->getGradeExec() << " and is signed" << std::endl;
	else
		o << "Form " << b->getName() << ", grade to sign " << b->getGradeSign() << ", grade to execute " << b->getGradeExec() << " and is not signed" << std::endl;
	return (o);
}
