/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:14:26 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/09 21:14:30 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	~Cure();

	Cure &operator=(const Cure &rhs);

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
}

#endif
