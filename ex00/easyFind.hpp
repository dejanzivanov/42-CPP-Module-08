/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 01:09:27 by dzivanov          #+#    #+#             */
/*   Updated: 2022/05/06 13:27:52 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

template<typename T> typename T::iterator easyfind(T &type, int value)
{
	typename T::iterator it = std::find(type.begin(), type.end(), value);

	if (it == type.end())
	{
		throw (std::exception());
	}
	else
		return it;
	return it;
}

#endif