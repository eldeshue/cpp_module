/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 01:41:29 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 03:42:08 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point
{
private:
	Fixed const *x, *y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	~Point();

	Point &operator=(const Point &rhs);

	Fixed const &getX() const;
	Fixed const &getY() const;
};

int ccw(const Point &pivot, const Point &p1, const Point &p2);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
