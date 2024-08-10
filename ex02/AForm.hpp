/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:21:18 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 15:29:10 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		const std::string	name;
		bool			signature;
		const int		grade_sign;
		const int		grade_exec;
		
	public :
		AForm(const std::string name);
		AForm(const int grade_sign, const int grade_exec);
		AForm(const std::string name, const int grade_sign, const int grade_exec);
		AForm(void);
		AForm(const AForm &f);
		AForm &operator=(const AForm &f);
		virtual ~AForm();
		
		//getters
		std::string	getName()      const;
		bool		getSignature() const;
		int		getGradeSign() const;
		int		getGradeExec() const;
	
		//setter
		void		setSignature(bool b);

		void		beSigned(const Bureaucrat &b);
		virtual void	execute(Bureaucrat const & executor) const = 0;
	
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm *b);

#endif