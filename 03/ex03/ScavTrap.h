/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:02:25 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 19:35:35 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.h"

#define SCAV_HP 100
#define SCAV_EP 50
#define SCAV_AP 20

class ScavTrap : public virtual ClapTrap
{
private:
	ScavTrap();

public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rhs);

	void attack(const std::string &target); /// override, key word is from C++11
	void guardGate();
};

#endif
