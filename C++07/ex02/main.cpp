/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:31:11 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/16 14:31:11 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int>			*i1 = new Array<int>(10);
	Array<int>			*i2 = new Array<int>(3);
	(*i1)[3] = 5;
	(*i2)[2] = -5;
	Array<int>			*i3 = new Array<int>();
	*i3 = *i1 + *i2;

	Array<Array<int> *>	*ii = new Array<Array<int> *>(3);

	ii->print();
	(*ii)[0] = i1;
	(*ii)[1] = i3;
	(*ii)[2] = i2;
	ii->print();
	ii->pushFront(i3);
	ii->pushBack(i3);
	ii->remove(2);
	ii->print();
	{
		Array<
			Array<int> *
		>	iibis(*ii);
		iibis.print();
	}
	try
	{
		for (char i = 20; i; --i)
		{
			i1->print();
			i1->remove(0);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete (ii);
	delete (i1);
	delete (i2);
	delete (i3);

	Array<
		Array<std::string>
	>	wahou = Array<Array<std::string> >(2);
	wahou[0] = Array<std::string>(3);
	wahou[0][0] = "b";
	wahou[0][1] = "bb";
	wahou[0][2] = "bbb";
	wahou[1] = Array<std::string>(1);
	wahou[1][0] = "END";
	wahou[1] += wahou[0];
	wahou.print();
	wahou.pushBack(wahou[0]);
	wahou.pushFront(wahou[1]);
	wahou.print();
	wahou.remove(3);
	wahou.remove(0);
	wahou.remove(0);
	wahou[0].remove(1);
	wahou[0].remove(1);
	wahou[0].remove(1);
	wahou.print();
}
