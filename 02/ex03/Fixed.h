/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:58:09 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/25 21:59:03 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
	static const int binaryPoint;
	int bitData;

public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &f);
	~Fixed();

	/* ---------- < operator overloading > ---------- */
	Fixed &operator=(const Fixed &rhs);

	// compare operator
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// operate and assign
	Fixed &operator+=(const Fixed &other);
	Fixed &operator-=(const Fixed &other);
	Fixed &operator*=(const Fixed &other);
	Fixed &operator/=(const Fixed &other);

	// arithmatic operator
	const Fixed operator+(const Fixed &other) const;
	const Fixed operator-(const Fixed &other) const;
	const Fixed operator*(const Fixed &other) const;
	const Fixed operator/(const Fixed &other) const;

	// prefix increase / decrease
	Fixed &operator++();
	Fixed &operator--();

	// postfix increase / decrease
	// parameter 'int' means nothing, just to identify
	// return const???
	Fixed operator++(int);
	Fixed operator--(int);

	/* ---------------------------------------------- */

	// get access
	int getRawBits() const;
	void setRawBits(int const raw);

	// explicit converter
	float toFloat() const;
	float toInt() const;

	// min, max
	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

// extraction operator function overloading, not a member function.
std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
