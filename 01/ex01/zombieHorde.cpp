/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:41:17 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 13:49:05 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *const ptr = new Zombie[N];

	for (int i = 0; i < N; ++i)
		ptr[i].setName(name);
	return ptr;
}
