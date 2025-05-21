#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	subjectMain(void)
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter*	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete (bob);
	delete (me);
	delete (src);
	return (0);
}

int	main(void) // MAIN FROM https://github.com/aceyzz/CPP04/blob/main/ex03/src/main.cpp
{
	std::cout << "MAIN\n\n";
	subjectMain();
	std::cout << "NOTMAIN\n\n";
	ICharacter	*john = new Character("John");
	ICharacter	*bill = new Character("Bill");
	std::cout << std::endl;

	IMateriaSource	*source = new MateriaSource();
	std::cout << std::endl;

	Ice		*ice = new Ice();
	Cure	*cure = new Cure();
	std::cout << std::endl;

	source->learnMateria(ice);
	source->learnMateria(cure);
	std::cout << std::endl;

	john->equip(source->createMateria("cure"));
	john->equip(source->createMateria("ice"));
	std::cout << std::endl;

	bill->equip(source->createMateria("cure"));
	bill->equip(source->createMateria("ice"));
	std::cout << std::endl;

	john->use(1, *bill);
	std::cout << std::endl;

	john->use(0, *john);
	std::cout << std::endl;

	bill->use(1, *john);
	std::cout << std::endl;

	bill->use(0, *bill);
	std::cout << std::endl;

	john->use(3, *bill);
	std::cout << std::endl;

	AMateria *tmp0 = ice;
	john->unequip(1);
	std::cout << std::endl;

	john->unequip(1);
	std::cout << std::endl;

	AMateria *tmp1 = cure;
	bill->unequip(0);
	std::cout << std::endl;

	bill->unequip(5);
	std::cout << std::endl;

	std::cout << "\n";

	delete (tmp0);
	delete (tmp1);
	//delete (source);
	delete (bill);
	delete (john);

	return (0);
}
