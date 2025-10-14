/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:24:21 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/14 20:24:21 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	Base
{
	public:
		virtual ~Base(void) { };
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base	*generate(void);
void	identify(const Base *const &p);
void	identify(const Base &p);

