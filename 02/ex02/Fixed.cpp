/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:46 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/17 20:02:44 by dogwak           ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &other) const
{
	return this->bitData > other.bitData;
}

bool Fixed::operator<(const Fixed &other) const
{
	return other > *this;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return !(*this < other);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return !(*this > other);
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->bitData == other.bitData;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return !(*this == other);
}

Fixed &Fixed::operator+=(const Fixed &other)
{
	this->bitData += other.bitData;
	return *this;
}

Fixed &Fixed::operator-=(const Fixed &other)
{
	this->bitData -= other.bitData;
	return *this;
}

Fixed &Fixed::operator*=(const Fixed &other)
{
	this->bitData =
		(static_cast<long long>(this->bitData) * static_cast<long long>(other.bitData)) >> binaryPoint;
	return *this;
}

Fixed &Fixed::operator/=(const Fixed &other)
{
	this->bitData =
		(static_cast<long long>(this->bitData) << binaryPoint) / static_cast<long long>(other.bitData);
	return *this;
}

const Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result(*this);
	return result += other;
}

const Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result(*this);
	return result -= other;
}

const Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result(*this);
	return result *= other;
}

const Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result(*this);
	return result /= other;
}

Fixed &Fixed::operator++()
{
	bitData++;
	return *this;
}

Fixed &Fixed::operator--()
{
	bitData--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	++(*this);
	return result;
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	--(*this);
	return result;
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

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return f1;
	else
		return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return f1;
	else
		return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return f1;
	else
		return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return f1;
	else
		return f2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	return os << f.toFloat();
}
