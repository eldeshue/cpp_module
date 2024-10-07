/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:27:33 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 20:17:39 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default ctor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy ctor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat dtor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	static_cast<WrongAnimal &>(*this) = static_cast<const WrongAnimal &>(rhs);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meowwww !!!\n";
}
