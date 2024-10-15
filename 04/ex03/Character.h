/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:20:23 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 19:35:25 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#define SLOT_SIZE 4

#include "ICharacter.h"
#include "AMateria.h"
#include <string>

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *slot[SLOT_SIZE];

	Character();

public:
	Character(const std::string &name);
	Character(const Character &other);
	virtual ~Character();

	Character &operator=(const Character &rhs);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	AMateria *getItem(int idx);
};

#endif
