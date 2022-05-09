/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:46:08 by dzivanov          #+#    #+#             */
/*   Updated: 2022/05/05 03:24:50 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(const Span& obj):vec_(obj.vec_)
{
	this->numberCount = obj.numberCount;
	this->maxLength  = obj.maxLength;
}

Span::~Span() {}

Span& Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return(*this);
	this->vec_ = rhs.vec_;
	this->numberCount = rhs.numberCount;
	this->maxLength = rhs.maxLength;
	return (*this);
}

Span::Span(unsigned int N)
{
	numberCount = 0;
	maxLength = N;
}

void Span::addNumber(int newNumber)
{
	try
	{
		if (numberCount < maxLength)
		{
			vec_.push_back(newNumber);
			numberCount++;
		}
		else
			throw(std::exception());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int randomNumber(void)
{
	int i = rand() % 100;
	return(i);
}

void printList(int value)
{
	std::cout << value << " " ;
}

void Span::massFill()
{
	srand(time(NULL));
	int oldSize = vec_.size();
	vec_.resize(maxLength);
	std::generate(vec_.begin() + oldSize, vec_.end(), randomNumber);

	//Prints the elements of the vector
	//std::for_each(vec_.begin(), vec_.end(), printList);

	numberCount = vec_.size();
}


int Span::shortestSpan()
{
	try
	{
		if (numberCount < 2)
			throw(std::exception());
		std::vector<int> vecCopy = vec_;
		std::sort(vecCopy.begin(), vecCopy.end());
		std::adjacent_difference(vecCopy.begin(), vecCopy.end(), vecCopy.begin());
		return(*(std::min_element(vecCopy.begin(), vecCopy.end())));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": Not enough values to calculate shortes span.";
		return (0);
	}
}

int Span::longestSpan()
{
	try
	{
		if (numberCount < 2)
			throw(std::exception());
		return(*(std::max_element(vec_.begin(), vec_.end())) - *(std::min_element(vec_.begin(), vec_.end())));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": Not enough values to calculate longest span. Value is therefore: ";
		return (0);
	}
}