/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:23:54 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 19:49:34 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal() : type("DEFAULT_ANIMAL_TYPE")
{
	std::cout << "Default wrong animal ctor called.\n";
}

WrongAnimal::WrongAnimal(const std::string &t) : type(t)
{
	std::cout << "WrongAnimal ctor, with " << type << " called\n ";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "Copy WrongAnimal ctor, with " << type << " called\n ";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal dtor, with " << type << " called.\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	type = rhs.type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "DEFAULT WRONG ANIMAL SOUND\n";
}

const std::string &WrongAnimal::getType() const
{
	return type;
}