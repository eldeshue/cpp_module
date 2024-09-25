/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:56:11 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/25 17:01:19 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <iostream>
#include "Weapon.h"

class HumanB
{
private:
	std::string name;
	const Weapon *weaponPtr;
	HumanB();

public:
	HumanB(const std::string &name);
	HumanB(const HumanB &h);
	~HumanB();

	HumanB &operator=(const HumanB &rhs);

	void setWeapon(Weapon &w);
	void attack() const;
};

#endif
