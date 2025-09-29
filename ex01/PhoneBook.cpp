/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:28:52 by calleaum          #+#    #+#             */
/*   Updated: 2025/06/24 11:58:48 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	std::cout << "Phonebook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}

static std::string display_short_string(const std::string str)
{
	if (str.length() < 10)
		return (str);
	else
		return (str.substr(0, 9) + ".");
}

bool PhoneBook::_is_valid_name(const std::string &str) const
{	
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-'))
			return (false);
	}
	return (true);
}

bool PhoneBook::_is_valid_phone(const std::string& str) const
{	
	if (str.empty())
		return (false);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (!((c >= '0' && c <= '9') || c == ' ' || c == '+'))
			return (false);
	}
	return (true);
}

bool PhoneBook::_is_not_empty(const std::string& str) const
{	
	return (!str.empty());
}

int PhoneBook::_get_next_index() const
{	
	static int index = 0;
	if (this->contacts[0].getFirstName().empty())
		return (0);
	index++;
	if (index == 8)
		index = 0;
	return (index);
}

void	PhoneBook::search()
{
	if (this->contacts[0].getFirstName().empty())
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	PhoneBook::_display_short();
	std::string	index;
	std::cout << "Enter index >";
	while (index.empty())
	{
		if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
			return ;
		}
		getline(std::cin, index);
		if (index.empty())
				std::cout << "Enter index >";
	}
	if (index.length() != 1 || index[0] < '1' || index[0] > '8')
	{
		std::cout
			<< "\033[1;31mInvalid index\033[0m" << std::endl;
		return ;
	}
	int	i = std::atoi(index.c_str()) - 1;
	if (this->contacts[i].getFirstName().empty())
	{
		std::cout
			<< "\033[1;31mInvalid index\033[0m"
			<< std::endl;
		return ;
	}
	std::cout << "Displaying contact " << i + 1 << std::endl;
	std::cout
		<< "Firstname: "
		<< this->contacts[i].getFirstName() << std::endl
		<< "Lastname: "
		<< this->contacts[i].getLastName() << std::endl
		<< "Nickname: "
		<< this->contacts[i].getNickname() << std::endl
		<< "Phone number: "
		<< this->contacts[i].getPhoneNumber() << std::endl
		<< "Darkest secret: "
		<< this->contacts[i].getDarkestSecret() << std::endl;
}

void PhoneBook::_display_short()
{	
	int idx = 0;
	if (this->contacts[idx].getFirstName().empty())
	{
		std::cout
			<< "Phonebook is empty"
			<< std::endl;
		return ;
	}
	std::cout
		<< "Displaying contacts" << std::endl;
	std::cout
		<< std::setw(45)
		<< std::setfill('-')
		<< ""
		<< std::endl
		<< std::setfill(' ');
	std::cout
		<< "|"
		<< std::setw(10)
		<< "index";
	std::cout
		<< "|"
		<< std::setw(10)
		<< "firstname";
	std::cout
		<< "|"
		<< std::setw(10)
		<< "lastname";
	std::cout
		<< "|"
		<< std::setw(10)
		<< "nickname";
	std::cout
		<< "|"
		<< std::endl;
	std::cout
		<< std::setw(45)
		<< std::setfill('-')
		<< ""
		<< std::endl
		<< std::setfill(' ');
	while (idx < 8)
	{
		if (this->contacts[idx].getFirstName().empty())
			break ;
		std::cout << "|"
			<< std::setw(10)
			<< idx + 1;
		std::cout
			<< "|"
			<< std::setw(10)
			<< display_short_string(this->contacts[idx].getFirstName());
		std::cout
			<< "|"
			<< std::setw(10)
			<< display_short_string(this->contacts[idx].getLastName());
		std::cout
			<< "|"
			<< std::setw(10)
			<< display_short_string(this->contacts[idx].getNickname());
		std::cout
			<< "|"
			<< std::endl;
		std::cout
			<< std::setw(45)
			<< std::setfill('-')
			<< ""
			<< std::endl
			<< std::setfill(' ');
		idx++;
	}
}

void	PhoneBook::add()
{
	std::string	question[5] = 
	{
		"Enter first name",
		"Enter last name",
		"Enter nick name",
		"Enter Phone number",
		"Enter darkest secret"
	};
	int idx = _get_next_index();
	std::cout << "Adding contact at index " << idx + 1 << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (this->_ask(question[i], this->contacts[idx], i) == EXIT_FAILURE)
		break ;
	}
}

int	PhoneBook::_ask(std::string question, Contact &contact, int index)
{
	std::string	input;
	bool		valid = false;

	while (!valid)
	{
		std::cout << question << " > ";
		while (input.empty())
		{
			if (std::cin.eof())
			{
				std::cout << "^D" << std::endl;
				return (EXIT_FAILURE);
			}
			getline(std::cin, input);
			if (input.empty())
				std::cout << "\033[1;31mError: Field cannot be empty. Please try again.\033[0m" << std::endl << question << " > ";
		}
		switch (index)
		{
			case (0):
				if (_is_valid_name(input))
				{					contact.setFirstName(input);
					valid = true;
				}
				else
				{
					std::cout << "\033[1;31mError: First name can only contain letters\033[0m" << std::endl;
					input.clear();
				}
				break ;
			case (1):
				if (_is_valid_name(input))
				{
					contact.setLastName(input);
					valid = true;
				}
				else
				{
					std::cout << "\033[1;31mError: Last name can only contain letters\033[0m" << std::endl;
					input.clear();
				}
				break ;
			case (2):
				if (_is_not_empty(input))
				{					contact.setNickname(input);
					valid = true;
				}
				else
				{
					std::cout << "\033[1;31mError: Nickname cannot be empty.\033[0m" << std::endl;
					input.clear();
				}
				break ;
			case (3):
				if (_is_valid_phone(input))
				{
					contact.setPhoneNumber(input);
					valid = true;
				}
				else
				{
					std::cout << "\033[1;31mError: Phone number can only contain digits, spaces, +\033[0m" << std::endl;
					input.clear();
				}
				break ;
			case (4):
				if (_is_not_empty(input))
				{
					contact.setDarkestSecret(input);
					valid = true;
				}
				else
				{
					std::cout << "\033[1;31mError: Darkest secret cannot be empty.\033[0m" << std::endl;
					input.clear();
				}
				break ;
		}
	}
	return (EXIT_SUCCESS);
}