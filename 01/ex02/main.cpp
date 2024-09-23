/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:20:40 by dogwak            #+#    #+#             */
/*   Updated: 2024/09/23 16:34:05 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string stringVAR("HI THIS IS BRAIN");
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "print memory addresses.\naddress of string variable : " << &stringVAR
			  << "\naddress of string pointer : "
			  << &stringPTR
			  << "\naddress of string reference : "
			  << &stringREF
			  << "\nprint values.\nvalue of string variable : "
			  << stringVAR
			  << "\nvalue of string pointer : "
			  << stringPTR
			  << "\nvalue of string reference : "
			  << stringREF
			  << '\n';
}
