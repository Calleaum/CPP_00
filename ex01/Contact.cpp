/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:29:00 by calleaum          #+#    #+#             */
/*   Updated: 2025/06/24 11:37:58 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()	
{
	if (this->firstName.empty() == false)
		std::cout << "Deleting " << this->firstName << std::endl;
	else
		std::cout << "Deleting an empty contact" << std::endl;
}

void	Contact::setFirstName(const std::string fn)
{
	firstName = fn;
}

void	Contact::setLastName(const std::string ln)
{
	lastName = ln;
}

void	Contact::setNickname(const std::string nick)
{
	nickname = nick;
}

void	Contact::setPhoneNumber(const std::string pn)
{
	phoneNumber = pn;
}

void	Contact::setDarkestSecret(const std::string ds)
{
	darkestSecret = ds;
}

std::string	Contact::getFirstName() const
{
	return (firstName);
}

std::string	Contact::getLastName() const
{
	return (lastName);
}

std::string	Contact::getNickname() const
{
	return (nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (darkestSecret);
}
