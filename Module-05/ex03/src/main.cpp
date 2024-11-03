/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/03 17:51:39 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Intern	intern;

	Bureaucrat john("John", 5);
	AForm *shrubbery(intern.makeForm("shrubbery creation", "garden"));
	AForm *robotomy(intern.makeForm("robotomy request", "Bender"));
	AForm *pardon(intern.makeForm("presidential pardon", "Alice"));
	AForm *unknown(intern.makeForm("unknown form", "target"));
	if (shrubbery)
	{
		john.signForm(*shrubbery);
		john.executeForm(*shrubbery);
		delete (shrubbery);
	}
	if (robotomy)
	{
		john.signForm(*robotomy);
		john.executeForm(*robotomy);
		delete (robotomy);
	}
	if (pardon)
	{
		john.signForm(*pardon);
		john.executeForm(*pardon);
		delete (pardon);
	}
	if (unknown)
		delete (unknown);
	return (0);
}
