/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:52:52 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 18:11:19 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <iostream>
#include "Weapon.h"

class HumanA
{
private:
	std::string name;
	const Weapon &weapon;
	HumanA();
	const HumanA &operator=(const HumanA &rhs);

public:
	HumanA(const std::string &name, const Weapon &weapon);
	HumanA(const HumanA &h);
	~HumanA();

	void attack() const;
};

#endif
