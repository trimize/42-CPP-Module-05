/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:06:25 by trimize           #+#    #+#             */
/*   Updated: 2024/07/25 15:29:21 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string.h>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int			grade;
	public:
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const Bureaucrat &b);
		~Bureaucrat();
		int			getGrade() const;
		const std::string	getName() const;
		void			setGrade(int grade);
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(Form &f);
	
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat *b);

#endif