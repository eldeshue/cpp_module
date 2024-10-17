/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:46 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/17 20:03:12 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::binaryPoint = 8;

Fixed::Fixed() : bitData(0)
{
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const int i) : bitData(i << binaryPoint)
{
	std::cout << "Int constructor called.\n";
}

Fixed::Fixed(const float f) : bitData(f * static_cast<float>(1 << binaryPoint))
{
	std::cout << "Float constructor called.\n";
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

float Fixed::toFloat() const
{
	return static_cast<float>(bitData) / static_cast<float>(1 << binaryPoint);
}

int Fixed::toInt() const
{
	return (bitData >> binaryPoint);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	return os << f.toFloat();
}
