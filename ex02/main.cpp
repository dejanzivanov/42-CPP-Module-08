/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:54:11 by dzivanov          #+#    #+#             */
/*   Updated: 2022/05/06 13:52:28 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <list>
#include <algorithm>

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

void subjectTest(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void vectorTest(void)
{
	std::vector<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << *(mstack.end() - 1) << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::vector<int>::iterator it = mstack.begin();
	std::vector<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}

int main(void)
{
	outputTitle("SUBJECT TEST");
	subjectTest();

	outputTitle("VECTOR TEST");
	vectorTest();

	return 0;
}