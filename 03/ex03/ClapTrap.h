/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:33:21 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 19:02:41 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <string>

#define CLAP_HP 10
#define CLAP_EP 10
#define CLAP_AP 0

class ClapTrap
{
private:
	ClapTrap();

protected:
	std::string name;
	unsigned int hitPoints, energyPoints, attackDamage;

public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	virtual ~ClapTrap();

	ClapTrap &operator=(const ClapTrap &rhs);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
