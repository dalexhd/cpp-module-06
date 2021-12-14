/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:56:47 by aborboll          #+#    #+#             */
/*   Updated: 2021/12/14 15:39:39 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

struct Data
{
	std::string s1;
	std::string s2;
};

/*
uintptr_t is an unsigned integer type that is capable of storing a data pointer. Which typically means that it's the same size as a pointer.

It is optionally defined in C++11 and later standards.

A common reason to want an integer type that can hold an architecture's pointer type is to perform integer-specific operations on a pointer, or to obscure the type of a pointer by providing it as an integer "handle".
*/
static	uintptr_t	serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

static	Data*	deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data	salut;

	salut.s1 = "Hola";
	salut.s2 = "Mundo";

	uintptr_t	serialized_ptr = serialize(&salut);

	std::cout << "Salut (serialized): " << serialized_ptr << std::endl;

	Data	*ptr = deserialize(serialized_ptr);

	std::cout << "Salut (deserialized): " << ptr->s1 << " " << ptr->s2 << std::endl;
	return (0);
}
