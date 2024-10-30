/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:32:41 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/30 18:52:50 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

// execute with : valgrind --leak-check=full ./cpp04ex02

int main()
{
	/*
	std::cout << "===== Abstract Class =====\n";
	Animal a;
	*/
	std::cout << "===== basic test =====\n";
	Animal *i = new Cat();
	Animal *j = new Dog();
	delete i;
	delete j;
	std::cout << "===== brain test =====\n";
	Brain *pB = new Brain();
	(*pB)[98] = "test";
	std::cout << "brain's 98'th idea : " << (*pB)[98] << '\n';
	std::cout << "assign idea, out of range.\n";
	try
	{
		(*pB)[101] = "error";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	delete pB;
	std::cout << "===== Ctor test =====\n";
	Cat *pC = new Cat();
	Dog *pD = new Dog();
	std::cout << "====== copy ctor test \n";
	Cat *pC_copy = new Cat(*pC);
	Dog *pD_copy = new Dog(*pD);
	std::cout << "===== access test ===\n";
	try
	{
		(*pC)[1055] = "test2";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		(*pD)[-5] = "test3";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "===== dtor test ====\n";
	delete pC;
	delete pD;
	delete pC_copy;
	delete pD_copy;
	std::cout << "===== half Dog, half Cat deleting test =====\n";
	Animal *animalPtrs[10];
	std::cout << "===== Creating Dogs =====\n";
	for (int i = 0; i < 5; ++i)
	{
		animalPtrs[i] = new Dog();
	}
	std::cout << "===== Creating Cats =====\n";
	for (int i = 5; i < 10; ++i)
	{
		animalPtrs[i] = new Cat();
	}
	std::cout << "===== Deleting Animalss =====\n";
	for (int i = 0; i < 10; ++i)
	{
		delete animalPtrs[i];
	}
	std::cout << "===== test done ====\n";
}
