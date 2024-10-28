/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blerouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:14:33 by blerouss          #+#    #+#             */
/*   Updated: 2024/02/29 12:19:02 by blerouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <stdlib.h>
# include <string>
# include <deque>
# include <list>
# include <vector>
# include <sys/time.h>

void			algoInDeque(char **argv);
void			algoInVector(char **argv);

template<typename T>
static int		binarySearch(T & pairing, std::pair<std::pair<int, int>, std::pair<int, int> > & pair)
{
	typename T::iterator	low = pairing.begin();
	typename T::iterator	high = pairing.end();
	typename T::iterator	mid = low + std::distance(low, high) / 2;

	while (low < high)
	{
		if (pair.second.second > mid->second.second)
			low = mid + 1;
		else
			high = mid;
		mid = low + std::distance(low, high) / 2;
	}
	pairing.insert(mid, pair);
	return std::distance(low, mid);
}

class argError : public std::exception
{

	public:

		virtual const char * what() const throw();

};

#endif
