/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:28:55 by calleaum          #+#    #+#             */
/*   Updated: 2025/06/24 11:38:03 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>
#include <iostream>

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;

		int		_ask(std::string question, Contact &contact, int index);
		int		_get_next_index() const;
		void	_display_short();
		bool	_is_valid_name(const std::string& str) const;
		bool	_is_valid_phone(const std::string& str) const;
		bool	_is_not_empty(const std::string& str) const;
		
	public:
		PhoneBook();
		~PhoneBook();

		void	search();
		void	add();
};