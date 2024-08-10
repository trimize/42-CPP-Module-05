/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:47:15 by trimize           #+#    #+#             */
/*   Updated: 2024/08/10 12:27:09 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5), target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), target("Zucc")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &ppf)
{
	*this = ppf;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
	if (this != &ppf)
		this->target = ppf.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignature())
		throw PresidentialPardonForm::FormNotSigned();
	else if (executor.getGrade() > this->getGradeExec())
		throw PresidentialPardonForm::GradeTooLowException();
	else
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

AForm	*PresidentialPardonForm::makeForm(AForm *aform, std::string name, std::string target)
{
	if (!aform && name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	return (aform);
}