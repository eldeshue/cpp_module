/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:26:52 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/02 19:35:26 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.h"

#define FRAG_HP 100
#define FRAG_EP 100
#define FRAG_AP 30

class FragTrap : public virtual ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	virtual ~FragTrap();

	FragTrap &operator=(const FragTrap &rhs);

	void highFivesGuys();
};

#endif
