/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:17:32 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 13:36:42 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie z("dogwak, stack allocated");
	z.announce();

	Zombie *zPtr = newZombie("dogwak, heap allocated");
	zPtr->announce();

	// random chump created, announce, deleted
	randomChump("dogwak, random chump");

	// heap zombie deleted
	delete zPtr;
	zPtr = NULL;

	// stack zombie deleted, compiler will insert the destructor
}
