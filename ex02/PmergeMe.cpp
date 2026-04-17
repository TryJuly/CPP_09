/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 07:13:26 by strieste          #+#    #+#             */
/*   Updated: 2026/04/17 16:12:12 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_hasLast = 0;
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	(*this) = copy;
	return ;
}

PmergeMe::~PmergeMe()
{
	_deque.erase(_deque.begin(), _deque.end());
	_dequePairs.erase(_dequePairs.begin(), _dequePairs.end());
	_vector.erase(_vector.begin(), _vector.end());
	_vectorPairs.erase(_vectorPairs.begin(), _vectorPairs.end());
	return ;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const &copy)
{
	if (this != &copy) {
		_deque = copy._deque;
		_dequePairs = copy._dequePairs;
		_vector = copy._vector;
		_vectorPairs = copy._vectorPairs;
		_last = copy._last;
		_hasLast = copy._hasLast;
	}
	return (*this);
}

std::vector<int>	PmergeMe::getVector() const
{ return (_vector); }

// static bool	Compare(std::pair<int, int> a, std::pair<int, int> b)
// { return (a.second < b.second); }

// void	PmergeMe::StartDeque(std::vector<int> tab)
// {}

static void	SortVectorPairs(std::vector<std::pair<int, int> > &vectorPairs);

void	PmergeMe::StartVector(std::vector<int> tab)
{
	size_t	size = tab.size();

	if (size % 2 == 0) {
		for (size_t	i = 0; i < size; i += 2)
			_vectorPairs.push_back(std::make_pair(tab[i], tab[i+1]));
		_hasLast = false;
	}
	else {
		for (size_t i = 0; i < size - 1; i += 2)
			_vectorPairs.push_back(std::make_pair(tab[i], tab[i+1]));
		_last = tab[size - 1];
		_hasLast = true;
	}

	size_t	sizePairs = _vectorPairs.size();

	for (size_t i = 0; i < sizePairs; i++) {
		if (_vectorPairs[i].first > _vectorPairs[i].second)
			std::swap(_vectorPairs[i].first, _vectorPairs[i].second);
	}

	SortVectorPairs(_vectorPairs);
	// std::sort(_vectorPairs.begin(), _vectorPairs.end(), Compare);

	for (size_t i = 0; i < sizePairs; i++)
		_vector.push_back(_vectorPairs[i].second);
	_vector.insert(_vector.begin(), _vectorPairs[0].first);

	size_t	current = 3;
	size_t	prev = 1;
	size_t	next;
	std::vector<int>::iterator	posIterator;
	while (current <= sizePairs) {
		for (size_t index = current; index > prev; index--) {
			if ((index - 1) >= sizePairs)
				continue ;
			posIterator = std::lower_bound(_vector.begin(), _vector.end(), _vectorPairs[index - 1].first);
			_vector.insert(posIterator, _vectorPairs[index - 1].first);
		}
		next = current + (2 * prev);
		prev = current;
		current = next;
	}
	if (prev < sizePairs) {
		for (size_t index = sizePairs; index > prev; index--) {
			posIterator = std::lower_bound(_vector.begin(), _vector.end(), _vectorPairs[index - 1].first);
			_vector.insert(posIterator, _vectorPairs[index - 1].first);
		}
	}
	if (_hasLast == true) {
		posIterator = std::lower_bound(_vector.begin(), _vector.end(), _last);
		_vector.insert(posIterator, _last);
	}
	return ;
}

static void	SortVectorPairs(std::vector<std::pair<int, int> > &vectorPairs)
{
	size_t	size = vectorPairs.size();
	if (size <= 1)
	return ;
	std::vector<std::pair<int, int> > left;
	std::vector<std::pair<int, int> > right;
	for (size_t	i = 0; (i < size / 2); i++)
		left.push_back(vectorPairs[i]);
	for (size_t i = (size / 2); i < size; i++)
		right.push_back(vectorPairs[i]);
	SortVectorPairs(left);
	SortVectorPairs(right);
	vectorPairs.clear();
	size_t	i = 0;
	size_t	j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].second < right[j].second) {
			vectorPairs.push_back(left[i]);
			i++;
		}
		else {
			vectorPairs.push_back(right[j]);
			j++;
		}
	}
	for (size_t count = i; count < left.size(); count++)
		vectorPairs.push_back(left[count]);
	for (size_t count = j; count < right.size(); count++)
		vectorPairs.push_back(right[count]);
	return ;
}