/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:56:47 by aborboll          #+#    #+#             */
/*   Updated: 2021/12/14 13:05:49 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static	int	randNumber(size_t min, size_t max)
{
	srand(time(NULL));
	return ((rand() % max) + min);
}

Base * generate(void)
{
	size_t	num = randNumber(1, 3);

	if (num == 1)
		return dynamic_cast<Base*>(new A);
	else if (num == 2)
		return dynamic_cast<Base*>(new B);
	return dynamic_cast<Base*>(new C);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << "\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << "\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << "\n";
}

void	identify(Base& p)
{
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << "\n";
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << "\n";
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << "\n";
}

int	main(void)
{
	Base * p;
	Base * p1;

	p = generate();
	usleep(1000000);
	p1 = generate();

	std::cout << "POINTER" << std::endl;
	identify(p);
	identify(p1);

	std::cout << "REFERENCE" << std::endl;
	identify(*p);
	identify(*p1);

	delete p;
	delete p1;
	return (0);
}
