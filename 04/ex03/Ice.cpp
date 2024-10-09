/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:16:07 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/09 21:23:41 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria("Ice")
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &rhs)
{
}

virtual AMateria *Ice::clone() const
{
	return new Ice();
}

virtual void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
