/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:27:35 by calleaum          #+#    #+#             */
/*   Updated: 2025/05/26 14:39:25 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{
	if(ac == 1)
		{
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			return (0);
		}
	for(int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for(size_t j = 0; j < arg.length(); j++)
		{
			std::cout << static_cast<char>(std::toupper(arg[j]));
		}
	}
	std::cout << std::endl;
	return (0);
}
