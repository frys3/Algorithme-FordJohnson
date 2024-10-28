/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blerouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:14:25 by blerouss          #+#    #+#             */
/*   Updated: 2024/02/29 12:18:55 by blerouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char * argError::what() const throw()
{
	return "Some arguments are not numbers.";
}

static void		getTime(int i)
{
	struct timeval	chrono;
	gettimeofday(&chrono, NULL);
	static unsigned long long int time = 0;
	if (i == 0)
		time = 0;
	if (!time)
		time = chrono.tv_sec * 1000000 + chrono.tv_usec;
	else
	{
		gettimeofday(&chrono, NULL);
		std::cout << chrono.tv_sec * 1000000 + chrono.tv_usec - time;
	}
}

static void			insertPairVector(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > & pairing, std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > & data)
{
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >::iterator	it = pairing.begin();
	std::pair<std::pair<int, int>, std::pair<int, int> >							tmp;
	int																				i = 0;
	int																				low = 0;
	int																				top = 1;
	int																				count = 0;
	int																				target = pairing.size();

	tmp.first = std::make_pair(-1, -1);
	while (target > count)
	{
		if (it->first.second != -1)
		{
			tmp.second = it->first;
			it->first = std::make_pair(-1, -1);
			binarySearch(pairing, tmp);
			count++;
		}
		else
			i--;
		if (i <= low)
		{
			i = low * 2 + top + count;
			low = top;
			top = i - count; 
			if (i >= static_cast<int>(pairing.size()))
				i = pairing.size() - 1;
		}
		it = pairing.begin() + i;
	}
	it = pairing.begin();
	while (it < pairing.end())
	{
		it->first = data[it->second.first].first;
		it->second = data[it->second.first].second;
		it++;
	}
}

static void			sortVector(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > & data)
{
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >			pairing;
	std::pair<std::pair<int, int>, std::pair<int, int> >						tmp;
	std::pair<std::pair<int, int>, std::pair<int, int> >						last;

	last.first = data.back().first;
	last.second = data.back().second;
	for (size_t i = 0; i < data.size() - 1; i+=2)
	{
		if (data[i].second.second > data[i + 1].second.second)
		{
			tmp.first = data[i + 1].second;
			tmp.first.first = static_cast<int>(i + 1);
			tmp.second = data[i].second;
			tmp.second.first = static_cast<int>(i);
		}
		else
		{
			tmp.first = data[i].second;
			tmp.first.first = static_cast<int>(i);
			tmp.second = data[i + 1].second;
			tmp.second.first = static_cast<int>(i + 1);
		}
		pairing.push_back(tmp);
	}
	if (pairing.size() > 1)
		sortVector(pairing);
	insertPairVector(pairing, data);
	if (data.size() % 2)
		binarySearch(pairing, last);
	data = pairing;
}

void			algoInVector(char **argv)
{
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >			data;
	int	index = 1;
	int	tmp;
	
	getTime(0);
	while (argv[index])
	{
    	std::istringstream iss((std::string(argv[index])));
    	if (iss >> tmp)
			data.push_back(std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, tmp)));
		else
			throw argError();
		index++;
	}
	std::cout << "Before : "; 
	for (size_t i = 0; i < data.size(); i++)
		std::cout << data[i].second.second << " ";
	std::cout << std::endl;
	sortVector(data);
	std::cout << "After  : ";
	for (size_t i = 0; i < data.size(); i++)
		std::cout << data[i].second.second << " ";
	std::cout << std::endl;
	std::cout << "Time to process with a std::vector : ";
	getTime(1);
	std::cout << "us" << std::endl;
}

static void			insertPairDeque(std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > > & pairing, std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > > & data)
{
	std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > >::iterator	it = pairing.begin();
	std::pair<std::pair<int, int>, std::pair<int, int> >							tmp;
	int																				i = 0;
	int																				low = 0;
	int																				top = 1;
	int																				count = 0;
	int																				target = pairing.size();

	tmp.first = std::make_pair(-1, -1);
	while (target > count)
	{
		if (it->first.second != -1)
		{
			tmp.second = it->first;
			it->first = std::make_pair(-1, -1);
			binarySearch(pairing, tmp);
			count++;
		}
		else
			i--;
		if (i <= low)
		{
			i = low * 2 + top + count;
			low = top;
			top = i - count; 
			if (i >= static_cast<int>(pairing.size()))
				i = pairing.size() - 1;
		}
		it = pairing.begin() + i;
	}
	it = pairing.begin();
	while (it < pairing.end())
	{
		it->first = data[it->second.first].first;
		it->second = data[it->second.first].second;
		it++;
	}
}

static void			sortDeque(std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > > & data)
{
	std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > >			pairing;
	std::pair<std::pair<int, int>, std::pair<int, int> >						tmp;
	std::pair<std::pair<int, int>, std::pair<int, int> >						last;

	last.first = data.back().first;
	last.second = data.back().second;
	for (size_t i = 0; i < data.size() - 1; i+=2)
	{
		if (data[i].second.second > data[i + 1].second.second)
		{
			tmp.first = data[i + 1].second;
			tmp.first.first = static_cast<int>(i + 1);
			tmp.second = data[i].second;
			tmp.second.first = static_cast<int>(i);
		}
		else
		{
			tmp.first = data[i].second;
			tmp.first.first = static_cast<int>(i);
			tmp.second = data[i + 1].second;
			tmp.second.first = static_cast<int>(i + 1);
		}
		pairing.push_back(tmp);
	}
	if (pairing.size() > 1)
		sortDeque(pairing);
	insertPairDeque(pairing, data);
	if (data.size() % 2)
		binarySearch(pairing, last);
	data = pairing;
}

void			algoInDeque(char **argv)
{
	std::deque<std::pair<std::pair<int, int>, std::pair<int, int> > >			data;
	int	index = 1;
	int	tmp;
	
	getTime(0);
	while (argv[index])
	{
    	std::istringstream iss((std::string(argv[index])));
    	if (iss >> tmp)
			data.push_back(std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, tmp)));
		else
			throw argError();
		index++;
	}
	sortDeque(data);
	std::cout << "Time to process with a std::deque : ";
	getTime(1);
	std::cout << "us" << std::endl;
}
