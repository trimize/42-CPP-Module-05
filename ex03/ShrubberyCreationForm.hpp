/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:43:17 by trimize           #+#    #+#             */
/*   Updated: 2024/08/10 18:28:08 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#define TREE "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string	target;
	public :
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &s);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &s);
		virtual void	execute(Bureaucrat const & executor) const;
		static AForm	*makeForm(AForm *aform, std::string name, std::string target);
};

#endif