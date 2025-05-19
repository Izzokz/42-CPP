/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:49:04 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 12:49:05 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*dog = new Dog();
	const Animal		*cat = new Cat();
	const Animal		meta1(*meta);
	const Animal		dog1(*dog);
	const Animal		cat1(*cat);
	const WrongAnimal	notmeta = WrongAnimal();
	const WrongAnimal	notacat = WrongCat();

	std::cout << "[cat] Bro is a " << cat->getType() << "...\n";
	std::cout << "[cat1] Bro is a " << cat1.getType() << "...\n";
	std::cout << "[dog] Bro is a " << dog->getType() << "...\n";
	std::cout << "[dog1] Bro is a " << dog1.getType() << "...\n";
	std::cout << "[meta] WTH??? Bro are you " << meta->getType() << "???\n";
	std::cout << "[meta1] WTH??? Bro are you " << meta1.getType() << "???\n";
	std::cout << "[notmeta] WTH??? Bro are you " << notmeta.getType() << "???\n";
	std::cout << "[notacat] WTH??? Bro are you " << notacat.getType() << "???\n";
	cat->makeSound();
	cat1.makeSound();
	dog->makeSound();
	dog1.makeSound();
	meta->makeSound();
	meta1.makeSound();
	notmeta.makeSound();
	notacat.makeSound();
	delete (dog);
	delete (cat);
	delete (meta);
	return (0);
}
