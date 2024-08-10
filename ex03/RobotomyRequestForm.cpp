/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:47:15 by trimize           #+#    #+#             */
/*   Updated: 2024/08/10 12:27:42 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45), target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), target("Zucc")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &r)
{
	*this = r;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
	if (this != &r)
		this->target = r.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignature())
		throw RobotomyRequestForm::FormNotSigned();
	else if (executor.getGrade() > this->getGradeExec())
		throw RobotomyRequestForm::GradeTooLowException();
	else
	{
		std::srand(std::time(NULL));
		std::cout << "Drilling noises..." << std::endl;
		bool	is_robot = std::rand() % 2 == 0;
		if (!is_robot)
			std::cout << this->target << "'s robotomy successfull" << std::endl;
		else
			std::cout << this->target << "'s robotomy failed" << std::endl;
	}
}

AForm	*RobotomyRequestForm::makeForm(AForm *aform, std::string name, std::string target)
{
	if (!aform && name == "robotomy request")
		return (new RobotomyRequestForm(target));
	return (aform);
}
