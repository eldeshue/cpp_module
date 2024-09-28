/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:29:13 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 15:32:28 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " is constructed.\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
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
	static_cast<ClapTrap>(*this) = static_cast<ClapTrap>(rhs);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " says HIGH FIVE GUYS!\n";
}
