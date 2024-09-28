/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:02:25 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 14:56:01 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();

public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rhs);

	void attack(const std::string &target); /// override, key word is from C++11
	void guardGate();
};

#endif
