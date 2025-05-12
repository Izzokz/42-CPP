/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:11:01 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/12 11:11:03 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int			_raw;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &cpy);
		Fixed &operator=(const Fixed &cpy);
		~Fixed(void);
		int			getRawBits(void) const;
		void		setRawBits(const int raw);
};

#endif
