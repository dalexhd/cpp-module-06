/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:32:50 by aborboll          #+#    #+#             */
/*   Updated: 2021/12/13 14:54:07 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <unistd.h>

#ifndef BASE_H
	#define BASE_H
	class Base
	{
		public:
			virtual	~Base() {
				std::cout << "Base destructor called!" << std::endl;
			};
	};
#endif

Base * generate(void);
void	identify(Base* p);
void	identify(Base& p);
