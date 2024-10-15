/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:19:11 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/09 20:27:31 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_H
#define I_MATERIA_SOURCE_H

#include <string>
#include "AMateria.h"

/*
	Interface for MateriaSource

	learn detail of other Materia and create learned materia

	something like factory
*/
class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
