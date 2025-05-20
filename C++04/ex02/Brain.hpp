/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:33:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 14:33:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain &cpy);
		Brain	&operator=(const Brain &cpy);
		~Brain(void);
		void		addIdea(const std::string &idea);
		void		addIdea(const std::string &idea, char slot);
		std::string	readThought(char slot) const;
};
