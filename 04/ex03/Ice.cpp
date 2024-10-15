/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:16:07 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 21:27:18 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"
#include "ICharacter.h"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria(other.getType())
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &rhs)
{
	rhs.getType();
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
