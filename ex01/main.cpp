/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:08:08 by dzivanov          #+#    #+#             */
/*   Updated: 2022/05/05 03:24:50 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <iomanip>


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
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void massFillTest(unsigned int value)
{
	Span test = Span(value);
	test.massFill();
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
}

int main()
{
	outputTitle("SUBJECT TEST");
	subjectTest();

	outputTitle("MASS FILL TEST 10000");
	massFillTest(10000);

	outputTitle("MASS FILL TEST 1000");
	massFillTest(1000);

	outputTitle("MASS FILL TEST 100");
	massFillTest(100);

	outputTitle("MASS FILL TEST 50");
	massFillTest(50);

	outputTitle("MASS FILL TEST 25");
	massFillTest(25);

	outputTitle("MASS FILL TEST 12");
	massFillTest(12);

	outputTitle("MASS FILL TEST 6");
	massFillTest(6);

	return 0;
}