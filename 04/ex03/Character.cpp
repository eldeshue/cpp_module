/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:11:25 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 22:12:51 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"

Character::Character(const std::string &name) : name(name)
{
	for (int i = 0; i < CHARAC_SLOT_SIZE; ++i)
		slot[i] = NULL;
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < CHARAC_SLOT_SIZE; ++i)
	{
		if (other.slot[i] != NULL)
			slot[i] = other.slot[i]->clone();
		else
			slot[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < CHARAC_SLOT_SIZE; ++i)
	{
		delete slot[i];
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < CHARAC_SLOT_SIZE; ++i)
			delete this->slot[i];
		this->name = rhs.name;
		for (int i = 0; i < CHARAC_SLOT_SIZE; ++i)
		{
			if (rhs.slot[i] != NULL)
				slot[i] = rhs.slot[i]->clone();
			else
				slot[i] = NULL;
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < CHARAC_SLOT_SIZE; ++i)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			break;
		}
	}
}

// do not delete.
// potential threat of resource handling
void Character::unequip(int idx)
{
	if (0 <= idx && idx < CHARAC_SLOT_SIZE)
		slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (0 <= idx && idx < CHARAC_SLOT_SIZE && slot[idx] != NULL)
		slot[idx]->use(target);
}

AMateria *Character::getItem(int idx)
{
	if (0 <= idx && idx < CHARAC_SLOT_SIZE)
		return slot[idx];
	else
		return NULL;
}
