/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:29:13 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/08 17:07:16 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " is constructed.\n";
	hitPoints = FRAG_HP;
	energyPoints = FRAG_EP;
	attackDamage = FRAG_AP;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << other.name << " is copy constructed.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destructed.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap " << rhs.name << " is assigned.\n";
	if (this != &rhs)
		static_cast<ClapTrap>(*this) = static_cast<ClapTrap>(rhs);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " says HIGH FIVE GUYS!\n";
}
