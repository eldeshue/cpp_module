/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:16:20 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 21:28:04 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"
#include "ICharacter.h"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria(other.getType())
{
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &rhs)
{
	rhs.getType();
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
