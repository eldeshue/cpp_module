/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:26:52 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/28 15:41:12 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	FragTrap &operator=(const FragTrap &rhs);

	void highFivesGuys();
};

#endif
