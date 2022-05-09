/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:27:01 by dzivanov          #+#    #+#             */
/*   Updated: 2022/05/06 13:56:07 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

/*
**	I would like to dedicate this module to my beatiful and very helpful friend
**	Jerry, also known as Meggy, Maggi, mammuller, aka Margarete Hanna Müller
*/


template<typename T> class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &mutantStack);
		virtual ~MutantStack();

		MutantStack &operator=(const MutantStack<T> &mutantStack);

		//typedef - user defined datatypes

		//It creates a container_type variable that is a stack of T.
		typedef typename std::stack<T>::container_type 		container_type;
		typedef typename container_type::iterator			iterator;
		typedef typename container_type::const_iterator		const_iterator;
		typedef typename container_type::reverse_iterator 	reverse_iterator;
		typedef typename container_type::const_reverse_iterator 	const_reverse_iterator;

		//It returns an iterator to the beginning of the container.
		iterator	begin(void) { return this->c.begin(); }
		iterator	end(void) { return this->c.end(); }

		const_iterator	begin(void) const { return this->c.begin(); }
		const_iterator	end(void) const { return this->c.end(); }

		reverse_iterator	rbegin(void) { return this->c.rbegin(); }
		reverse_iterator	rend(void) { return this->c.rend(); }

		const_reverse_iterator	rbegin(void) const { return this->c.rbegin(); }
		const_reverse_iterator	rend(void) const { return this->c.rend(); }

};

template<typename T> MutantStack<T>::MutantStack(void)
{
	return;
}

template<typename T> MutantStack<T>::MutantStack(const MutantStack<T> &mutantStack)
{
	*this = mutantStack;
}

template<typename T> MutantStack<T>::~MutantStack()
{
	return ;
}

template<typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack &mutantStack)
{
	if(*this != mutantStack)
	{
		static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(mutantStack);
	}
	return *this;
}

#endif