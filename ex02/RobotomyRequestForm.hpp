/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:44:38 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 18:04:08 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "cstdlib"
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private :
		std::string	target;
	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm &r);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &r);
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif