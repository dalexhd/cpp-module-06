/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:18:37 by aborboll          #+#    #+#             */
/*   Updated: 2022/01/24 18:13:34 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

//Convert constructors & destructors
Convert::Convert(void) : value("")
{
	d_val.err = "\0";
	i_val.err = "\0";
	f_val.err = "\0";
	c_val.err = "\0";
}

Convert::Convert(std::string value) : value(value)
{
	d_val.err = "\0";
	i_val.err = "\0";
	f_val.err = "\0";
	c_val.err = "\0";
}

Convert::~Convert()
{
	std::cout << "Destructor called" << std::endl;
}

std::string	Convert::getValue(void) const
{
	return (this->value);
}

std::string itoa(int a)
{
	if (a == 0)
		return "0";
	std::string res = "";
	int tmp = a;
	while (tmp != 0)
	{
		res = (char)(tmp % 10 + '0') + res;
		tmp /= 10;
	}
	return res;
}

void	Convert::setValue(std::string val)
{
	this->value = val.length() == 1 && std::isalpha(val[0]) ? itoa((double)val[0]) : val;
	double tmp = std::stod(this->value);
	if (!std::isinf(tmp) && !std::isnan(tmp) && (tmp > INT_MAX || tmp < INT_MIN))
		throw std::runtime_error("impossible");
	this->setDoubleVal(tmp);
}

// Convert
void	Convert::toInt(double val)
{
	int i = static_cast<int>(val);
	if (val > INT_MAX || val < INT_MIN || std::isinf(val) || std::isnan(val))
		throw std::runtime_error("impossible");
	else
		this->setIntVal(i);
}

void	Convert::toFloat(double val)
{
	int f = static_cast<float>(val);
	if (std::isnan(val))
		throw std::runtime_error("nanf");
	if (std::isinf(val) && val > 0)
		throw std::runtime_error("inf");
	else if (std::isinf(val) && val < 0)
		throw std::runtime_error("-inf");
	else
		this->setFloatVal(f);
}


void	Convert::toChar(double val)
{
	char c;

	if (val >= 32 && val <= 126)
		c = (char)val;
	else if (this->value.length() > 1)
		throw std::runtime_error("impossible");
	else
		throw std::runtime_error("Non displayable");
	this->setCharVal(c);
}

// Set Err
void	Convert::setDoubleErr(std::string error)
{
	this->d_val.err = error;
}

void	Convert::setIntErr(std::string error)
{
	this->i_val.err = error;
}

void	Convert::setFloatErr(std::string error)
{
	this->f_val.err = error;
}

void	Convert::setCharErr(std::string error)
{
	this->c_val.err = error;
}

// Get err
std::string	Convert::getCharErr(void)
{
	return this->c_val.err;
}

std::string	Convert::getFloatErr(void)
{
	return this->f_val.err;
}

std::string	Convert::getIntErr(void)
{
	return this->i_val.err;
}

std::string	Convert::getDoubleErr(void)
{
	return this->d_val.err;
}

// Set val
void	Convert::setDoubleVal(double value)
{
	this->d_val.value = value;
}

void	Convert::setIntVal(int value)
{
	this->i_val.value = value;
}

void	Convert::setFloatVal(float value)
{
	this->f_val.value = value;
}

void	Convert::setCharVal(char value)
{
	this->c_val.value = value;
}

// Get val
void	Convert::getFloatVal(void)
{
	float f;
	std::string	err;

	err = this->getFloatErr();
	if (!err.empty())
	{
		std::cout << err;
		return ;
	}
	f = this->f_val.value;
	if (f - static_cast<int>(f) != 0)
		std::cout << f << "f";
	else
		std::cout << f << ".0f";
}

void	Convert::getDoubleVal(void)
{
	double d;
	std::string	err;

	err = this->getDoubleErr();
	if (!err.empty())
	{
		std::cout << err;
		return ;
	}
	d = this->d_val.value;
	if (d - static_cast<int>(d) != 0)
		std::cout << d;
	else
		std::cout << d << ".0";
}

void	Convert::getIntVal(void)
{
	std::string	err;

	err = this->getIntErr();
	if (!err.empty())
	{
		std::cout << err;
		return ;
	}
	std::cout << this->i_val.value;
}

void	Convert::getCharVal(void)
{
	std::string	err;

	err = this->getCharErr();
	if (!err.empty())
	{
		std::cout << err;
		return ;
	}
	std::cout << "'" << this->c_val.value << "'";
}

double	Convert::getDval(void)
{
	return this->d_val.value;
}

//Convert operators
std::ostream & operator<<(std::ostream & stream , Convert & content)
{
	stream << "char: ";
	content.getCharVal();
	stream << std::endl;
	stream << "int: ";
	content.getIntVal();
	stream << std::endl;
	stream << "float: ";
	content.getFloatVal();
	stream << std::endl;
	stream << "double: ";
	content.getDoubleVal();
	stream << std::endl;
	return stream;
}

