/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:23:06 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 20:46:52 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.h"

int main()
{
	DiamondTrap test("test");
	static_cast<ClapTrap &>(test).takeDamage(0); // show member variables.
	test.whoAmI();
	test.attack("target");

	DiamondTrap test2(test);
	static_cast<ClapTrap &>(test).takeDamage(0); // show member variables.
	test2.whoAmI();
	test2.attack("target2");

	test.attack("target");
	test.attack("target");

	// poly morphism
	test = DiamondTrap("test3");
	ClapTrap &testClap = test;
	ScavTrap &testScav = test;
	FragTrap &testFrag = test;

	testClap.attack("target3");
	testScav.attack("target3");
	testFrag.attack("target3");

	testClap.takeDamage(10);
	testScav.takeDamage(10);
	testFrag.takeDamage(10);

	testClap.beRepaired(10);
	testScav.beRepaired(10);
	testFrag.beRepaired(10);

	testClap.takeDamage(20);
	testScav.takeDamage(20);
	testFrag.takeDamage(20);

	testScav.attack("target4");
	test.attack("target4");

	testScav.guardGate();
	testFrag.highFivesGuys();
	test.whoAmI();
}
