/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:58:09 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/17 20:01:29 by dogwak           ###   ########.fr       */
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

	// operator overloading
	Fixed &operator=(const Fixed &rhs);

	// get access
	int getRawBits() const;
	void setRawBits(int const raw);

	// explicit converter
	float toFloat() const;
	int toInt() const;
};

// extraction operator function overloading, not a member function.
std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
