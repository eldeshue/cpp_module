/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:51:34 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/25 17:04:29 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(const std::string &name) : name(name), weaponPtr(NULL)
{
}

HumanB::HumanB(const HumanB &h) : name(h.name), weaponPtr(h.weaponPtr)
{
}

HumanB::~HumanB()
{
}

HumanB &HumanB::operator=(const HumanB &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->weaponPtr = rhs.weaponPtr;
	}
	return *this;
}

void HumanB::setWeapon(Weapon &w)
{
	this->weaponPtr = &w;
}

void HumanB::attack() const
{
	if (weaponPtr != NULL)
		std::cout << name << " attack with their " << weaponPtr->getType() << '\n';
	else
		std::cout << "cannot dereference pointer to the weapon.\n";
}
