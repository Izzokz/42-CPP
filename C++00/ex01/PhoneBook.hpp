/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:20:57 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/09 11:03:37 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

extern char	gEOF;

class	PhoneBook
{
	private:
		Contact		contacts[8];
		unsigned char	index : 3;

	public:
		void		add(void);
		void		search(void);
		PhoneBook(void);
};

#endif
