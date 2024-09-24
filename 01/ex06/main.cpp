/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:27:26 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/24 20:49:57 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int argc, char *argv[])
{
	Harl h;
	if (argc != 2)
	{
		std::cerr << "Error : wrong number of argument.\n";
		return 1;
	}
	const std::string query(argv[1]);
	h.complain(query);
	return 0;
}
