/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:27:26 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/24 20:24:02 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main()
{
	Harl h;
	std::string query;

	while (true)
	{
		std::cout << "waiting for query : ";
		std::cin >> query;
		if (query == "exit")
			break;
		h.complain(query);
		std::cout << std::endl;
	}
}
