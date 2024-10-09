/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:32:41 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/09 16:43:50 by dogwak           ###   ########.fr       */
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
	// brain test.
	Brain b;
	b[98] = "test";
	try
	{
		b[101] = "error";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
