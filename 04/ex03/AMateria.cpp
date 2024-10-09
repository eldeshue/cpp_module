/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:30:12 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/09 21:02:53 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
}
