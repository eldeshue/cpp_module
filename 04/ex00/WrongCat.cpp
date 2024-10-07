/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:27:33 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 17:31:26 by dogwak           ###   ########.fr       */
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
}

void WrongCat::makeSound()
{
	std::cout << "Wrong Meowwww !!!\n";
}
