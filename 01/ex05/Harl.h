/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:27:57 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/24 20:31:36 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

class Harl
{
private:
	void (Harl::* f[4])();
	static const std::string levels[4];

	void debug();
	void info();
	void warning();
	void error();

	Harl(const Harl &h);
	const Harl &operator=(const Harl &rhs);

public:
	Harl();
	~Harl();

	void complain(std::string level);
};

#endif
