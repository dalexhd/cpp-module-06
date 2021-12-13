/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:56:47 by aborboll          #+#    #+#             */
/*   Updated: 2021/12/13 14:11:48 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

struct Data
{
	std::string s1;
	std::string s2;
};


uintptr_t	serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}


// Docs: https://stackoverflow.com/questions/43342397/serialize-and-deserialize-datas-with-reinterpret-cast
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
