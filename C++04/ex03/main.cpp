#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	AMateria	*i = new Ice();
	src->learnMateria(i);
	delete (i);
	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "* CREATING NEW CHARACTER *\n";
	ICharacter	*notme = new Character(*(Character *)me);
	std::cout << "* CREATION PROCESS TERMINATED *\n";
	std::cout << "* CREATING NEW CHARACTER+ *\n";
	Character	notme2("kou");
	tmp = src->createMateria("cure");
	notme2.equip(tmp);
	std::cout << notme2.getName() << " is my name.\n";
	std::cout << "* NEW CHARACTER+ INITIALIZED *\n";
	notme2 = *(Character *)notme;
	std::cout << "* REPLACEMENT PROCESS TERMINATED *\n";
	std::cout << notme2.getName() << " is my name.\n";
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter	*bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(5, *bob);
	me->unequip(5);
	me->unequip(3);
	tmp = (*(Character *)me).collectMateria(0);
	me->unequip(0);
	delete (tmp);
	me->unequip(0);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(NULL);
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	notme2.equip(tmp);
	notme->use(1, *bob);
	notme->use(2, *bob);
	notme2.use(1, *notme);
	delete (bob);
	delete (me);
	delete (notme);
	delete (src);
	return (0);
}
