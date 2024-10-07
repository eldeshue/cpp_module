/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:35:51 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 16:55:03 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const std::string &t);
	Animal(const Animal &other);
	virtual ~Animal();

	Animal &operator=(const Animal &rhs);

	void makeSound();
};

#endif
