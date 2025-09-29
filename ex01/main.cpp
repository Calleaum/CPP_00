/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:28:49 by calleaum          #+#    #+#             */
/*   Updated: 2025/06/24 13:05:38 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook book;
    std::string command;

    while (true)
	{
        std::cout << "Enter a command > ";
        std::getline(std::cin, command);
		
        if (std::cin.eof())
		{
			std::cout << "^D" << std::endl;
            break;
		}
        if (command.empty())
            std::cout << "\033[1;31mError: Empty command. Please enter ADD, SEARCH, or EXIT.\033[0m" << std::endl;
        else if (command == "EXIT" || command == "exit")
            break;
        else if (command == "ADD" || command == "add")
            book.add();
        else if (command == "SEARCH" || command == "search")
            book.search();
        else
            std::cout << "\033[1;31mInvalid command: " << command << "\nCommand list: ADD, SEARCH or EXIT\033[0m" << std::endl;
    }
    return (0);
}