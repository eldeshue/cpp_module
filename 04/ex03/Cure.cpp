/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:16:20 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 18:12:27 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"
#include "ICharacter.h"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &rhs)
{
}

AMateria *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
