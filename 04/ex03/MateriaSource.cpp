/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:19:50 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 21:06:46 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < SLOT_SIZE; ++i)
		slot[i] = NULL;
}

// no ownership
MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < SLOT_SIZE; ++i)
	{
		slot[i] = other.slot[i];
	}
}

// no ownership
MateriaSource::~MateriaSource()
{
}

// no ownership
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i = 0; i < SLOT_SIZE; ++i)
		slot[i] = rhs.slot[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < SLOT_SIZE; ++i)
	{
		if (slot[i] == NULL)
			slot[i] = m;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SLOT_SIZE; ++i)
	{
		if (slot[i]->getType() == type)
			return slot[i]->clone();
	}
	return NULL;
}
