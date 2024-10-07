/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:32:41 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 20:15:28 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
	// basic polymorphism
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	// wrong cat
	const WrongAnimal *wMeta = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	const WrongCat &l = *(static_cast<const WrongCat *>(k));
	std::cout << k->getType() << " " << std::endl;
	std::cout << l.getType() << " " << std::endl;
	k->makeSound();
	l.makeSound();

	delete wMeta;
	delete k;
}
