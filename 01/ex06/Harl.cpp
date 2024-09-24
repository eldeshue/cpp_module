/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:34:15 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/24 20:51:28 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

static const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do !\n\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n";
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
	int key = mapFromLevelToKey(level);

	switch (key)
	{
	case -1:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	case 0:
		(this->*(f[key++]))();
		__attribute__((fallthrough));
	case 1:
		(this->*(f[key++]))();
		__attribute__((fallthrough));
	case 2:
		(this->*(f[key++]))();
		__attribute__((fallthrough));
	default:
		(this->*(f[key]))();
		break;
	}
	return;
}
