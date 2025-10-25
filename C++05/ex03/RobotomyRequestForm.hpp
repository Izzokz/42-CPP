/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:51:01 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/22 14:51:01 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private: /* -Data- */
		std::string	_target;

	public: /* -CDstructors- */
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm(void);
	public: /* -Operator- */
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &cpy);
	public: /* -Method- */
		void		execute(const Bureaucrat &exe) const;
};
