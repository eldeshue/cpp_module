/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:11:09 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 19:49:33 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.h"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + BASE_NAME_SUFFIX), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << "DiamondTrap " << name << " is constructed.\n";
	hitPoints = FRAG_HP;
	energyPoints = SCAV_EP;
	attackDamage = FRAG_AP;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << name << " is copy constructed.\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is destructed.\n";
}

ClapTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap " << name << " is copy assigned.\n";
	*(static_cast<ClapTrap *>(this)) = static_cast<const ClapTrap &>(rhs);
	DiamondTrap::name = rhs.DiamondTrap::name;
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	return static_cast<ScavTrap *>(this)->attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Diamond Name : " << DiamondTrap::name << " | Clap Name : " << ClapTrap::name << '\n';
}
