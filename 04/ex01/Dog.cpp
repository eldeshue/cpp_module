/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:06:40 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/08 17:02:33 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default ctor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy ctor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog dtor called\n";
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		static_cast<Animal &>(*this) = static_cast<const Animal &>(rhs);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark !!!\n";
}
