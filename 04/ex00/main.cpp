/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:32:41 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/07 20:44:32 by dogwak           ###   ########.fr       */
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
	// basic polymorphism, pointer to base can call derived's member function. because of virtual
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl; // cat
	std::cout << i->getType() << " " << std::endl; // dog
	i->makeSound();								   // meow expected
	j->makeSound();								   // bark expected
	meta->makeSound();							   // default animal sound expected
	delete meta;
	delete i;
	delete j;

	// wrong cat, without virtual, cannot call derived's member founction
	const WrongAnimal *wMeta = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	const WrongCat &l = *(static_cast<const WrongCat *>(k));
	std::cout << k->getType() << " " << std::endl;
	std::cout << l.getType() << " " << std::endl;
	k->makeSound(); // default wrong animal sound expected
	l.makeSound();	// wrong meow expected

	delete wMeta;
	delete k;

	// reference
	const Dog d;
	const Animal &refAnimal = d;

	std::cout << d.getType() << std::endl; // Dog expected
	d.makeSound();						   // Bark expected

	std::cout << refAnimal.getType() << std::endl; // Dog expected
	refAnimal.makeSound();						   // Bark expected
}
