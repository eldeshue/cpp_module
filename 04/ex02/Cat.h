/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:12:27 by dogwak            #+#    #+#             */
/*   Updated: 2024/10/08 18:17:46 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
private:
	Brain *pBrain;

public:
	Cat();
	Cat(const Cat &other);
	~Cat();

	Cat &operator=(const Cat &rhs);
	std::string &operator[](int idx);
	const std::string &operator[](int idx) const;

	virtual void makeSound() const;
};

#endif
