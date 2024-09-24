/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:34:15 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/24 20:30:42 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

static const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do !\n ";
}

void Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

Harl::Harl()
{
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
}

Harl::~Harl()
{
}

int mapFromLevelToKey(const std::string &level)
{
	int key = -1;

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			key = i;
			break;
		}
	}
	return key;
}

void Harl::complain(std::string level)
{
	const int key = mapFromLevelToKey(level);

	if (key == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return;
	}
	return (this->*(f[key]))();
}
