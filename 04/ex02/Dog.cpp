/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:06:40 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/08 18:21:33 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal("Dog"), pBrain(new Brain())
{
	std::cout << "Dog default ctor called\n";
}

Dog::Dog(const Dog &other) : Animal(other), pBrain(new Brain())
{
	std::cout << "Dog copy ctor called\n";
	*pBrain = *(other.pBrain);
}

Dog::~Dog()
{
	std::cout << "Dog dtor called\n";
	delete pBrain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		static_cast<Animal &>(*this) = static_cast<const Animal &>(rhs);
		*pBrain = *(rhs.pBrain);
	}
	return *this;
}

std::string &Dog::operator[](int idx)
{
	return (*pBrain)[idx];
}

const std::string &Dog::operator[](int idx) const
{
	return (*pBrain)[idx];
}

void Dog::makeSound() const
{
	std::cout << "Bark !!!\n";
}
