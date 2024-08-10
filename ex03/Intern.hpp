/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:44:38 by trimize           #+#    #+#             */
/*   Updated: 2024/08/10 18:27:12 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <fstream>
#include "AForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(Intern &i);
		Intern &operator=(const Intern &i);
		AForm	*makeForm(std::string name, std::string target);
};

#endif