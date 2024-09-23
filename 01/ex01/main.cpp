/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:17:32 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 13:52:24 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie *horde = zombieHorde(13, "dogwak");

	for (int i = 0; i < 13; ++i)
	{
		horde[i].announce();
	}

	// delete and delete[] are different.
	delete[] horde;
}
