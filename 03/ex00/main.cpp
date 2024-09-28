/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:23:06 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 13:33:31 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.h"

int main()
{
	std::cout << "   < test 1 : death. >\n";
	ClapTrap test("test1");
	std::cout << " test 1 : before death.\n";
	test.attack("target");
	test.beRepaired(11);
	test.takeDamage(100);

	std::cout << " test 1 : after death.\n";
	test.attack("target");
	test.beRepaired(200);
	test.takeDamage(9);

	std::cout << "   < test 2 : exhaustion. >\n";
	ClapTrap test2("test2");
	for (int i = 0; i < 11; ++i)
	{
		test2.attack("test2");
	}
}
