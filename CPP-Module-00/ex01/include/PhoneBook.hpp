/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:25 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/16 18:39:01 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX 8
# define WIDTH 10
# include "Contact.hpp"
# include <iomanip>
# include <iostream>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);
	int commandPrompt(void);

  private:
	void display(void);
	void search(void);
	int size;
	Contact contacts[MAX];
};

#endif /* PHONEBOOK_HPP */
