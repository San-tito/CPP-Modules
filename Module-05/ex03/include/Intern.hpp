/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/03 17:55:49 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

# define NUM_FORMS 3

class Intern
{
  public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern(void);

	AForm *makeForm(const std::string &form_name, const std::string &target);

  private:
	static AForm *makeShrubberyForm(const std::string &target);
	static AForm *makeRobotomyForm(const std::string &target);
	static AForm *makePresidentialForm(const std::string &target);
};

#endif /* INTERN_HPP */
