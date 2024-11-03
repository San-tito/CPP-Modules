/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/03 16:10:39 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class	Bureaucrat;

class AForm
{
  public:
	AForm(void);
	AForm(const std::string &name, int sign_grade, int exec_grade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm(void);

	const std::string &getName(void) const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
		public:
		const char *what(void) const throw();
	};

  protected:
	void checkExecution(const Bureaucrat &executor) const;

  private:
	const std::string name_;
	bool is_signed_;
	const int sign_grade_;
	const int exec_grade_;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif /* AFORM_HPP */
