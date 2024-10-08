/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:02:44 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/08 18:17:53 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
private:
	Brain *pBrain;

public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog &operator=(const Dog &rhs);
	std::string &operator[](int idx);
	const std::string &operator[](int idx) const;

	virtual void makeSound() const;
};

#endif
