/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:20:45 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/07 16:20:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set(std::string var, std::string value)
{
	if (var == "fname")
		this->fname = value;
	else if (var == "lname")
		this->lname = value;
	else if (var == "nname")
		this->nname = value;
	else if (var == "phone")
		this->phone = value;
	else if (var == "darkestSecret")
		this->darkestSecret = value;
}

std::string	Contact::get(std::string var)
{
	if (var == "fname")
		return (this->fname);
	if (var == "lname")
		return (this->lname);
	if (var == "nname")
		return (this->nname);
	if (var == "phone")
		return (this->phone);
	if (var == "darkestSecret")
		return (this->darkestSecret);
	return (NULL);
}
