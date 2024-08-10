/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:51:48 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 17:40:38 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137), target("home")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &s)
{
	*this = s;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	if (this != &s)
		this->target = s.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignature())
		throw ShrubberyCreationForm::FormNotSigned();
	else if (executor.getGrade() > this->getGradeExec())
		throw ShrubberyCreationForm::GradeTooLowException();
	else
	{
		std::ofstream	outfile;

		outfile.open((this->target + "_shrubbery").c_str());
		if (outfile.fail())
		{
			std::cout << "Could not open file" << std::endl;
			return ;
		}
		outfile << TREE;
		outfile.close();
	}		
}