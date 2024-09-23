/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:46:44 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 18:11:29 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(const std::string &name, const Weapon &weapon) : name(name), weapon(weapon)
{
}

HumanA::HumanA::HumanA(const HumanA &h) : name(h.name), weapon(h.weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
	std::cout << name << " attack with their " << weapon.getType() << '\n';
}
