/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:26:47 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/23 16:26:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <iostream>

class	BitcoinExchange
{
	private: /* -Data- */
		static std::map<long, float>		_db;
	private: /* -Internal Method- */
		static const float					&getCorrespondence(const long &formatDate);
	private: /* -Pure Static Class- */
		BitcoinExchange(void) { };
		~BitcoinExchange(void) { };

	public: /* -Setter- */
		static void							setDB(const std::string &datafileName);
	public: /* -Getter- */
		static const std::map<long, float>	&getDB(void);
		static void							getExchange(const std::string &date, const float &number);
		static void							getExchangeFromFile(const std::string &file);
};
