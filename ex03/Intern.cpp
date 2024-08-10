/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:47:15 by trimize           #+#    #+#             */
/*   Updated: 2024/08/10 17:58:49 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(Intern &ppf)
{
	*this = ppf;
}

Intern& Intern::operator=(const Intern &ppf)
{
	(void)ppf;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm	*aform;

	try
	{
		aform = AForm::makeForm(name, target);
	}
	catch(AForm::NotRecognizedForm &e)
	{
		std::cerr << e.what() << '\n';
		aform = NULL;
	}
	return	(aform);
}