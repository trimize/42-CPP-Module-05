/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:32:15 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 15:18:07 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name) : name(name), grade_sign(150), grade_exec(150)
{
	this->setSignature(false);
}

AForm::AForm(const int grade_sign, const int grade_exec) : name("default"), grade_sign(grade_sign), grade_exec(grade_exec)
{
	this->setSignature(false);
	if (grade_sign > 150)
		throw AForm::GradeTooLowException();
	else if (grade_sign < 1)
		throw AForm::GradeTooHighException();
	if (grade_exec > 150)
		throw AForm::GradeTooLowException();
	else if (grade_exec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const std::string name, const int grade_sign, const int grade_exec) : name(name), grade_sign(grade_sign), grade_exec(grade_exec)
{
	this->setSignature(false);
	if (grade_sign > 150)
		throw AForm::GradeTooLowException();
	else if (grade_sign < 1)
		throw AForm::GradeTooHighException();
	if (grade_exec > 150)
		throw AForm::GradeTooLowException();
	else if (grade_exec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm() : name("default"), grade_sign(150), grade_exec(150)
{
	this->setSignature(false);
}

AForm::AForm(const AForm &f) : signature(f.getSignature()), grade_sign(f.getGradeSign()), grade_exec(f.getGradeExec())
{
	*this = f;
}

AForm& AForm::operator=(const AForm &f)
{
	if (this != &f)
		setSignature(f.getSignature());
	return (*this);
}

AForm::~AForm()
{
	
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool		AForm::getSignature() const
{
	return (this->signature);
}

int		AForm::getGradeSign() const
{
	return (this->grade_sign);
}

int		AForm::getGradeExec() const
{
	return (this->grade_exec);
}

void		AForm::setSignature(bool b)
{
	this->signature = b;
}

void		AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeSign())
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
		std::cout << std::endl;
	}
	else
	{
		this->setSignature(true);
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm's grade too high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm's grade too low");
}

const char *AForm::FormNotSigned::what(void) const throw()
{
	return ("AForm's is not signed");
}

std::ostream	&operator<<(std::ostream &o, AForm *b)
{
	
	if (b->getSignature())
		o << "AForm " << b->getName() << ", grade to sign " << b->getGradeSign() << ", grade to execute " << b->getGradeExec() << " and is signed" << std::endl;
	else
		o << "AForm " << b->getName() << ", grade to sign " << b->getGradeSign() << ", grade to execute " << b->getGradeExec() << " and is not signed" << std::endl;
	return (o);
}
