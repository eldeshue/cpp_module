/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:30:12 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/15 21:20:56 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"
#include "ICharacter.h"
#include <iostream>

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	// unreachable
	target.getName();
}
