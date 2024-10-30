/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:19:50 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/30 19:06:24 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MS_SLOT_SIZE; ++i)
		slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < MS_SLOT_SIZE; ++i)
	{
		if (other.slot[i] != NULL)
			slot[i] = other.slot[i]->clone();
		else
			slot[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MS_SLOT_SIZE; ++i)
	{
		delete slot[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < MS_SLOT_SIZE; ++i)
			delete this->slot[i];
		for (int i = 0; i < MS_SLOT_SIZE; ++i)
		{
			if (rhs.slot[i] != NULL)
				slot[i] = rhs.slot[i]->clone();
			else
				slot[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < MS_SLOT_SIZE; ++i)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m->clone();
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MS_SLOT_SIZE; ++i)
	{
		if (slot[i] != NULL && slot[i]->getType() == type)
			return slot[i]->clone();
	}
	return NULL;
}
