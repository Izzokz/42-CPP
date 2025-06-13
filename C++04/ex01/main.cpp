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

void	mindReader(Brain *occurence)
{
	char		i;
	std::string	thought;

	i = -1;
	while (++i < 100)
	{
		thought = occurence->readThought(i);
		if (thought != "")
			std::cout << "[" << (int)i << "] " << thought << "\n";
	}
}

int	main(void)
{
	{
		Animal		nothing;
		const Animal	*dog = new Dog();
		const Animal	*cat = new Cat();
		dog->getBrain()->addIdea("Bro");
		dog->getBrain()->addIdea("Bor", 98);
		cat->getBrain()->addIdea("MIAOUH!");
		const Animal	*dog1 = new Dog(*(Dog *)dog);
		const Animal	*cat1 = new Cat(*(Cat *)cat);

		dog1->getBrain()->addIdea("Rob");
		for (char i = 0; i < 34; ++i)
			cat1->getBrain()->addIdea("Mia...", i * 3);
		const Animal	*dog2 = new Dog(*(Dog *)dog1);
		const Animal	*cat2 = new Cat(*(Cat *)cat1);
		cat->makeSound();
		dog->makeSound();
		std::cout << "DOG\n";
		mindReader(dog->getBrain());
		std::cout << "DOG1\n";
		mindReader(dog1->getBrain());
		std::cout << "DOG2\n";
		mindReader(dog2->getBrain());
		std::cout << "CAT\n";
		mindReader(cat->getBrain());
		std::cout << "CAT1\n";
		mindReader(cat1->getBrain());
			std::cout << "CAT2\n";
		mindReader(cat2->getBrain());
		delete (dog);
		delete (cat);
		delete (dog1);
		delete (cat1);
		delete (dog2);
		delete (cat2);
	}
	{
		const Animal	*cadog[100];

		for (char i = 0; i < 50; i++)
			*(cadog + i) = new Cat();
		for (char i = 50; i < 100; i++)
			*(cadog + i) = new Dog();
		for (char i = 0; i < 100; i++)
			delete (*(cadog + i));
	}
	return (0);
}
