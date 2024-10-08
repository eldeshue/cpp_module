/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:11:21 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/08 18:16:48 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat"), pBrain(new Brain())
{
	std::cout << "Cat default ctor called\n";
}

Cat::Cat(const Cat &other) : Animal(other), pBrain(new Brain())
{
	std::cout << "Cat copy ctor called\n";
	*pBrain = *(other.pBrain);
}

Cat::~Cat()
{
	std::cout << "Cat dtor called\n";
	delete pBrain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		static_cast<Animal &>(*this) = static_cast<const Animal &>(rhs);
		*pBrain = *rhs.pBrain;
	}
	return *this;
}

std::string &Cat::operator[](int idx)
{
	return (*pBrain)[idx];
}

const std::string &Cat::operator[](int idx) const
{
	return (*pBrain)[idx];
}

void Cat::makeSound() const
{
	std::cout << "Meowwww !!!\n";
}
