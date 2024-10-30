/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:10:28 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/30 17:52:11 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include "MateriaSource.h"

#include "Ice.h"
#include "Cure.h"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	// unequip test
	tmp = static_cast<Character *>(me)->getItem(0);
	me->unequip(0);
	delete tmp;

	tmp = static_cast<Character *>(me)->getItem(1);
	me->unequip(1);
	delete tmp;

	tmp = static_cast<Character *>(me)->getItem(1);
	me->unequip(2);
	delete tmp;

	// delete resources
	delete bob;
	delete me;
	delete src;
}
