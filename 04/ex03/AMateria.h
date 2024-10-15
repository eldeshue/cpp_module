/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:51:06 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/14 22:11:29 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_H
#define A_MATERIA_H

#include <string>

class ICharacter;
/*
	Abstract Material Class

	base class for Materia, equiped by Character
*/
class AMateria
{
protected:
	std::string type;
	AMateria();

public:
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	virtual ~AMateria();

	AMateria &operator=(const AMateria &rhs);

	std::string const &getType() const; // Returns the materia type

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
