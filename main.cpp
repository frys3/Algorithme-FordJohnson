/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blerouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:14:12 by blerouss          #+#    #+#             */
/*   Updated: 2024/02/23 17:57:28 by bastien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "The programs needs numbers as argument." << std::endl;
		return 1;
	}
	try
	{
		algoInVector(argv);
		algoInDeque(argv);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
