/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:39:51 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 20:16:57 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>

Animal::Animal() : type("DEFAULT_ANIMAL_TYPE")
{
	std::cout << "Default animal ctor called.\n";
}

Animal::Animal(const std::string &t) : type(t)
{
	std::cout << "Animal ctor, with " << type << " called\n ";
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Copy Animal ctor, with " << type << " called\n ";
}

Animal::~Animal()
{
	std::cout << "Animal dtor, with " << type << " called.\n";
}

Animal &Animal::operator=(const Animal &rhs)
{
	type = rhs.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "DEFAULT ANIMAL SOUND\n";
}

const std::string &Animal::getType() const
{
	return type;
}
