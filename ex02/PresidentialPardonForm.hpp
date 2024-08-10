/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:44:38 by trimize           #+#    #+#             */
/*   Updated: 2024/08/10 11:48:05 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "cstdlib"

class PresidentialPardonForm : public AForm
{
	private :
		std::string	target;
	public :
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &ppf);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ppf);
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif