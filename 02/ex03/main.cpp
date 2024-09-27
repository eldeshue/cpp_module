/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:15:33 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 04:01:23 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.h"

int main()
{
	Point a, b, c, p;

	// triangle 1
	a = Point(0, 0);
	b = Point(3, 0);
	c = Point(0, 3);
	p = Point(1.33f, 1.67f);
	std::cout << std::boolalpha << bsp(a, b, c, p) << '\n';

	// triangle 2
	a = Point(-2, 0);
	b = Point(1, -1);
	c = Point(3, 4);
	p = Point(-2, 0);
	std::cout << std::boolalpha << bsp(a, b, c, p) << '\n';
}
