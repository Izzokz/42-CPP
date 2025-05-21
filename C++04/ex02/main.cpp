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
	std::string	thought;

	for (char i = 0; i < 100; i++)
	{
		thought = occurence->readThought(i);
		if (thought != "")
			std::cout << "[" << (int)i << "] " << thought << "\n";
	}
}

int	main(void)
{
	{
		//const AAnimal	cannotCompile;
		const AAnimal	*dog = new Dog();
		const AAnimal	*cat = new Cat();
		dog->getBrain()->addIdea("Bro");
		dog->getBrain()->addIdea("Bor", 98);
		cat->getBrain()->addIdea("MIAOUH!");
		const AAnimal	*dog1 = new Dog(*(Dog *)dog);
		const AAnimal	*cat1 = new Cat(*(Cat *)cat);

		dog1->getBrain()->addIdea("Rob");
		for (char i = 0; i < 34; ++i)
			cat1->getBrain()->addIdea("Mia...", i * 3);
		const AAnimal	*dog2 = new Dog(*(Dog *)dog1);
		const AAnimal	*cat2 = new Cat(*(Cat *)cat1);
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
		const AAnimal	*cadog[100];

		for (char i = 0; i < 50; i++)
			*(cadog + i) = new Cat();
		for (char i = 50; i < 100; i++)
			*(cadog + i) = new Dog();
		for (char i = 0; i < 100; i++)
			delete (*(cadog + i));
	}
	{
		const AAnimal	*a1 = new Dog();
		AAnimal	*a2 = new Dog(*(Dog *)a1);

		*a2 = *a1;
		mindReader(a2->getBrain());
		delete (a1);
		delete (a2);
	}
	return (0);
}
