/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/03 16:36:03 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat john("John", 5);
	Bureaucrat jane("Jane", 145);
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Alice");
	john.signForm(shrubbery);
	jane.signForm(robotomy);
	john.signForm(pardon);
	john.executeForm(shrubbery);
	john.executeForm(robotomy);
	john.executeForm(pardon);
	return (0);
}
