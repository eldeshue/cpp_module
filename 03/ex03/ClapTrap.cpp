/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:52:41 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 19:03:25 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(CLAP_HP), energyPoints(CLAP_EP), attackDamage(CLAP_AP)
{
	std::cout << "ClapTrap, " << name << "'s constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap, " << name << "'s copy constructor called.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap, " << name << "'s destructor called.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap, " << rhs.name << " is assigned.\n";
	if (this == &rhs)
		return *this;
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
		energyPoints--;
	}
	else
		std::cout << "Not alive, do nothing.\n";
	std::cout << "hp : " << hitPoints << " | ep : " << energyPoints << '\n';
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
	if (hitPoints <= amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "hp : " << hitPoints << " | ep : " << energyPoints << '\n';
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " is repaired, " << amount << " points of hp restored!\n";
		hitPoints += amount;
		energyPoints--;
	}
	else
		std::cout << "Not alive, do nothing.\n";
	std::cout << "hp : " << hitPoints << " | ep : " << energyPoints << '\n';
	return;
}
