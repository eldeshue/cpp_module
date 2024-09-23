/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weaph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:47:05 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 18:09:51 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon() : type("UNARMED")
{
}

Weapon::Weapon(const std::string &t) : type(t)
{
}

Weapon::Weapon(const Weapon &w) : type(w.type)
{
}

Weapon::~Weapon()
{
}

const Weapon &Weapon::operator=(const Weapon &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &t)
{
	this->type = t;
}
