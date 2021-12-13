/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:28:58 by aborboll          #+#    #+#             */
/*   Updated: 2021/12/13 13:53:41 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static	int	error(std::string error)
{
	std::cerr << error << std::endl;
	return (-1);
}

int main(int argc, char *argv[])
{
	Convert	converter;
	double	value;

	if (argc < 2 || argc > 2)
		return error("Please insert a correct number of params. Ex \"./convert [number|string|float]\"");
	try
	{
		converter.setValue(argv[1]);
	}
	catch(const std::exception& e)
	{
		converter.setDoubleErr("Conversion is impossible");
		converter.setIntErr("Conversion is impossible");
		converter.setFloatErr("Conversion is impossible");
	}

	value = converter.getDval();
	try
	{
		converter.toInt(value);
	}
	catch(const std::exception& e)
	{
		converter.setIntErr(e.what());
	}

	try
	{
		converter.toFloat(value);
	}
	catch(const std::exception& e)
	{
		converter.setFloatErr(e.what());
	}

	try
	{
		converter.toChar(value);
	}
	catch(const std::exception& e)
	{
		converter.setCharErr(e.what());
	}
	std::cout << converter << std::endl;
	return (0);
}
