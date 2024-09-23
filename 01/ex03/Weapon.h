/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:16 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 18:15:46 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	Weapon(const Weapon &w);
	Weapon(const std::string &t);
	~Weapon();
	const Weapon &operator=(const Weapon &rhs);

	const std::string &getType() const;
	void setType(const std::string &t);
};

#endif
