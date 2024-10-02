/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:42:39 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 19:33:03 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"

#define BASE_NAME_SUFFIX "_clap_name"

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap
{
private:
	std::string name;

public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	virtual ~DiamondTrap();

	ClapTrap &operator=(const DiamondTrap &rhs);

	void attack(const std::string &target); /// override, key word is from C++11

	void whoAmI();
};

#endif
