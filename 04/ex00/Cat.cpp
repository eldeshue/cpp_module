/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:11:21 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 17:13:06 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default ctor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy ctor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat dtor called\n";
}

Cat &Cat::operator=(const Cat &rhs)
{
	static_cast<Animal &>(*this) = static_cast<const Animal &>(rhs);
}

void Cat::makeSound()
{
	std::cout << "Meowwww !!!\n";
}