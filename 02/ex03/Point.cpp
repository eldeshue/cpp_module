/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:26:28 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 03:52:38 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point() : x(new Fixed()), y(new Fixed())
{
}

Point::Point(const float x, const float y) : x(new Fixed(x)), y(new Fixed(y))
{
}

Point::Point(const Point &other) : x(new Fixed(other.getX())), y(new Fixed(other.getY()))
{
}

Point::~Point()
{
	delete x;
	delete y;
}

Point &Point::operator=(const Point &rhs)
{
	delete x;
	delete y;
	x = new Fixed(rhs.getX());
	y = new Fixed(rhs.getY());
	return *this;
}

Fixed const &Point::getX() const
{
	return *x;
}

Fixed const &Point::getY() const
{
	return *y;
}

int ccw(const Point &pivot, const Point &p1, const Point &p2)
{
	const Fixed x1 = p1.getX() - pivot.getX();
	const Fixed y1 = p1.getY() - pivot.getY();
	const Fixed x2 = p2.getX() - pivot.getX();
	const Fixed y2 = p2.getY() - pivot.getY();
	const Fixed result = x1 * y2 - y1 * x2;
	if (result.toInt() > 0)
		return 1;
	else if (result.toInt() < 0)
		return -1;
	else
		return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	return ((ccw(a, b, c) * ccw(a, b, point)) >= 0) && ((ccw(b, c, a) * ccw(b, c, point)) >= 0) && ((ccw(c, a, b) * ccw(c, a, point)) >= 0);
}
