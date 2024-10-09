/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:13:08 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/09 21:13:13 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	~Ice();

	Ice &operator=(const Ice &rhs);

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
}

#endif
