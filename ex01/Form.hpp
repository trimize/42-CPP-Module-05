/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:21:18 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 15:29:10 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string	name;
		bool			signature;
		const int		grade_sign;
		const int		grade_exec;
		
	public :
		Form(const std::string name);
		Form(const int grade_sign, const int grade_exec);
		Form(const std::string name, const int grade_sign, const int grade_exec);
		Form(void);
		Form(const Form &f);
		Form &operator=(const Form &f);
		~Form();
		
		//getters
		std::string	getName()      const;
		bool		getSignature() const;
		int		getGradeSign() const;
		int		getGradeExec() const;
	
		//setter
		void		setSignature(bool b);

		void		beSigned(Bureaucrat &b);
	
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
};

std::ostream	&operator<<(std::ostream &o, Form *b);

#endif