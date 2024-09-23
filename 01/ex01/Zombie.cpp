/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:09:24 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 13:51:46 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() : name("UNNAMED")
{
	std::cout << "Zombie " << name << " is default constructed." << std::endl;
}

Zombie::Zombie(const std::string &name) : name(name)
{
	std::cout << "Zombie " << name << " is constructed." << std::endl;
}

Zombie::Zombie(const Zombie &z) : name(z.name)
{
	std::cout << "Zombie " << name << " is copy constructed." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " is destructed." << std::endl;
}

const Zombie &Zombie::operator=(const Zombie &rhs)
{
	if (this != &rhs)
		name = rhs.name;
	return *this;
}

void Zombie::setName(const std::string &name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
