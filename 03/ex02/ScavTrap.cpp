/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:16:03 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 14:29:08 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " is constructed.\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << other.name << " is copy constructed.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destructed.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap " << rhs.name << " is assigned.\n";
	static_cast<ClapTrap>(*this) = static_cast<ClapTrap>(rhs);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
		energyPoints--;
	}
	else
		std::cout << "Not alive, do nothing.\n";
	std::cout << "hp : " << hitPoints << " | ep : " << energyPoints << '\n';
	return;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode.\n";
}
