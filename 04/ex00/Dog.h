/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:02:44 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 17:08:58 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog &operator=(const Dog &rhs);

	void makeSound();
};

#endif
