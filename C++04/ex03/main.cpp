/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:13:53 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/06/13 16:13:54 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	std::cout << "\e[31;1m* CREATING MATERIASOURCE *\e[0m" << std::endl;
	IMateriaSource	*src = new MateriaSource();
	std::cout << "\e[31;1* CREATION PROCESS TERMINATED *\e[0m" << std::endl;
	std::cout << "\e[31;1* STARTING FILLING MATERIASOURCE *\e[0m" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	std::cout << "\e[31;1m* FILLED MATERIASOURCE *\e[0m" << std::endl;
	std::cout << "\e[31;1m* TRYING KEEPING FILLING IT *\e[0m" << std::endl;
	AMateria	*i = new Ice();
	src->learnMateria(i);
	delete (i);
	std::cout << std::endl;

	std::cout << "\e[31;1m* CREATING NEW CHARACTER *\e[0m" << std::endl;
	ICharacter	*me = new Character("me");
	std::cout << "\e[31;1m* CREATION PROCESS TERMINATED *\e[0m" << std::endl;
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "\e[31;1m* CREATING NEW CHARACTER+ *\e[0m" << std::endl;
	ICharacter	*notme = new Character(*(Character *)me);
	std::cout << "\e[31;1m* CREATION PROCESS TERMINATED *\e[0m" << std::endl;
	std::cout << "\e[31;1m* CREATING NEW CHARACTER++ *\e[0m" << std::endl;
	Character	notme2("kou");
	tmp = src->createMateria("cure");
	notme2.equip(tmp);
	std::cout << notme2.getName() << " is my name." << std::endl;
	std::cout << "\e[31;1m* NEW CHARACTER++ INITIALIZED *\e[0m" << std::endl;
	notme2 = *(Character *)notme;
	std::cout << "\e[31;1m* REPLACEMENT PROCESS TERMINATED *\e[0m" << std::endl;
	std::cout << notme2.getName() << " is my name." << std::endl << std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter	*bob = new Character("bob");
	std::cout << "\e[31;1m* TRYING TO USE KNOWN MATERIAS *\e[0m" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "\e[31;1m* TRYING TO USE (void *)0 MATERIA *\e[0m" << std::endl;
	me->use(2, *bob);
	std::cout << "\e[31;1m* TRYING TO USE MATERIA OUT OF BOUNDS *\e[0m" << std::endl;
	me->use(5, *bob);
	std::cout << std::endl;

	std::cout << "\e[31;1m* TRYING TO UNEQUIP MATERIA OUT OF BOUNDS *\e[0m" << std::endl;
	me->unequip(5);
	std::cout << "\e[31;1m* TRYING TO UNEQUIP (void *)0 MATERIA *\e[0m" << std::endl;
	me->unequip(3);
	std::cout << "\e[31;1m* TRYING TO UNEQUIP KNOWN MATERIA *\e[0m" << std::endl;
	tmp = (*(Character *)me).collectMateria(0);
	me->unequip(0);
	delete (tmp);
	std::cout << "\e[31;1m* TRYING TO UNEQUIP UNEQUIPPED MATERIA *\e[0m" << std::endl;
	me->unequip(0);
	std::cout << std::endl;

	std::cout << "\e[31;1m* FILLING CHARACTER WITH MATERIAS *\e[0m" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << "\e[31;1m* TRYING TO EQUIP (void *)0 MATERIA *\e[0m" << std::endl;
	me->equip(NULL);
	std::cout << "\e[31;1m* KEEPING FILLING CHARACTER WITH MATERIAS *\e[0m" << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "\e[31;1m* CHARACTER FILLED *\e[0m" << std::endl;
	std::cout << "\e[31;1m* TRYING KEEPING FILLING IT *\e[0m" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << "\e[31;1m* JUST ME HAVING FUN *\e[0m" << std::endl;
	notme2.equip(tmp);
	notme->use(1, *bob);
	notme->use(2, *bob);
	notme2.use(1, *notme);
	std::cout << std::endl;

	std::cout << "\e[31;1m* DELETING EVERYTHING *\e[0m" << std::endl;
	delete (bob);
	delete (me);
	delete (notme);
	delete (src);
	return (0);
}
