/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/03 16:37:16 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class	AForm;

class Bureaucrat
{
  public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat(void);

	const std::string &getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm &form);
	void executeForm(const AForm &form) const;

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what(void) const throw();
	};

  private:
	const std::string name_;
	int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif /* BUREAUCRAT_HPP */
