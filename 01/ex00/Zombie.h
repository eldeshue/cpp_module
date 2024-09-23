/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:08:51 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 13:15:58 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;
	Zombie();

public:
	Zombie(const std::string &name);
	Zombie(const Zombie &z);
	~Zombie();

	const Zombie &operator=(const Zombie &rhs);
	void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
