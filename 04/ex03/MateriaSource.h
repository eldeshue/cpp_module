/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:20:23 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 21:39:28 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#define MS_SLOT_SIZE 4

#include "IMateriaSource.h"
#include "AMateria.h"

/*
	class for holding AMateria

	no ownership
	just copy, no cloning
	just assing, no deleting
*/
class MateriaSource : public IMateriaSource
{
private:
	AMateria *slot[MS_SLOT_SIZE];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	virtual ~MateriaSource();

	MateriaSource &operator=(const MateriaSource &rhs);

	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};

#endif
