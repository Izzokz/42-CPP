/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:20:51 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/09 11:02:22 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class	Contact
{
	private:
		std::string	fname;
		std::string	lname;
		std::string	nname;
		std::string	phone;
		std::string	darkestSecret;
	public:
		void		set(std::string var, std::string value);
		std::string	get(std::string var);
		Contact(void);
};

#endif
