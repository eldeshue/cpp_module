/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:23:06 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 15:21:59 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.h"

int main()
{
	ScavTrap test1("test1");

	test1.attack("target1");
	static_cast<ClapTrap &>(test1).attack("target1");
	static_cast<ClapTrap &>(test1).takeDamage(99);
	static_cast<ClapTrap &>(test1).beRepaired(30);
	static_cast<ClapTrap &>(test1).beRepaired(30);
	test1.attack("target1");
}
