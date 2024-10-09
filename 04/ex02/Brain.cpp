/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:56:00 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/08 17:01:28 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.h"

Brain::Brain()
{
	std::cout << "Default Brain ctor called.\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy Brain ctor called.\n";
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain dtor called.\n";
}

Brain &Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}

std::string &Brain::operator[](int idx)
{
	if (0 > idx || 100 <= idx)
		throw std::out_of_range("index out of range at brain.");
	return ideas[idx];
}

const std::string &Brain::operator[](int idx) const
{
	if (0 > idx || 100 <= idx)
		throw std::out_of_range("index out of range at brain.");
	return ideas[idx];
}
