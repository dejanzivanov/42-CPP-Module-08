/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:34:08 by dzivanov          #+#    #+#             */
/*   Updated: 2022/05/05 03:24:50 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <ctime>
#include <cstddef>

class Span
{
private:
	Span();
	std::vector<int> vec_;

public:
	Span(const Span& obj);
	~Span();
	Span& operator=(const Span& rhs);
	Span(unsigned int N);
	void addNumber(int newNumber);
	void massFill();
	int shortestSpan();
	int longestSpan();

	int numberCount;
	int maxLength;

};
int randomNumber();
