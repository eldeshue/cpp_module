/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:23:06 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 20:20:26 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.h"

int main()
{
	DiamondTrap test("test");

	test.attack("target");
	test.whoAmI();

	DiamondTrap test2(test);

	test2.attack("target2");
	test2.whoAmI();
}
