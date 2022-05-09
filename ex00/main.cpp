/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 01:08:08 by dzivanov          #+#    #+#             */
/*   Updated: 2022/05/06 13:48:36 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <iostream>

void printList(int value)
{
	std::cout << value << " " ;
}

static void	outputTitle(std::string title)
{
	std::string	toPrint;
	int	size = 60;
	int	n;

	toPrint = " " + title + " ";
	n = toPrint.size();
	if (n > size)
	{
		toPrint = toPrint.substr(0, size - 2);
		toPrint[size - 4] = '.';
		toPrint[size - 3] = ' ';
		n = toPrint.size();
	}
	std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
	std::cout << toPrint.substr(n / 2, n);
	std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}

void listTest(void)
{
	srand(time(NULL));

	std::list<int> lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(std::rand() % 10);
	std::cout << "***TRYING TO FIND NUMBER 5 IN LIST***"<< std::endl;
	try
	{
		std::cout << std::distance(lst.begin(), easyfind(lst, 5)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "***PRINTING LIST***"<< std::endl;
	std::for_each(lst.begin(), lst.end(), printList);
}

void dequeTest(void)
{
	srand(time(NULL));

	std::deque<int> lst;
	for (int i = 0; i < 20; i++)
		lst.push_back(std::rand() % 10);
	std::cout << "***TRYING TO FIND NUMBER 3 IN DEQUE***"<< std::endl;
	try
	{
		std::cout << std::distance(lst.begin(), easyfind(lst, 3)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "***PRINTING DEQUE***"<< std::endl;
	std::for_each(lst.begin(), lst.end(), printList);
}

void vectorTest(void)
{
	srand(time(NULL));

	std::vector<int> lst;
	for (int i = 0; i < 30; i++)
		lst.push_back(std::rand() % 10);
	std::cout << "***TRYING TO FIND NUMBER 4 IN VECTOR***"<< std::endl;
	try
	{
		std::cout << std::distance(lst.begin(), easyfind(lst, 4)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "***PRINTING VECTOR***"<< std::endl;
	std::for_each(lst.begin(), lst.end(), printList);
	std::cout << std::endl;
}

int main(void)
{
	outputTitle("LIST TEST");
	listTest();

	outputTitle("DEQUE TEST");
	dequeTest();

	outputTitle("VECTOR TEST");
	vectorTest();

	return 0;
}