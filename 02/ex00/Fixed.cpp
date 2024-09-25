/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:46 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/25 18:26:16 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

const int Fixed::binaryPoint = 8;

Fixed::Fixed() : bitData(0)
{
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called.\n";
	*this = f;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called.\n";
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called.\n";
	if (this != &rhs)
		this->bitData = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called.\n";
	return bitData;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called.\n";
	bitData = raw;
}
