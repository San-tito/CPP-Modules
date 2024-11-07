/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/03 16:36:20 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name_("unnamed"), grade_(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name),
	grade_(grade)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_),
	grade_(other.grade_)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	grade_ = other.grade_;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

const std::string &Bureaucrat::getName(void) const
{
	return (name_);
}

int Bureaucrat::getGrade(void) const
{
	return (grade_);
}

void Bureaucrat::incrementGrade(void)
{
	if (grade_ <= MAX_GRADE)
		throw GradeTooHighException();
	grade_--;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade_ >= MIN_GRADE)
		throw GradeTooLowException();
	grade_++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << name_ << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << name_ << " couldn't execute " << form.getName() << " because " << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName();
	os << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}