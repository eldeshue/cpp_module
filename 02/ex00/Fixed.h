/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:58:09 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/25 18:07:54 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

class Fixed
{
private:
	static const int binaryPoint;
	int bitData;

public:
	Fixed();
	Fixed(const Fixed &f);
	~Fixed();

	Fixed &operator=(const Fixed &rhs);

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif
