/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:15:33 by aborboll          #+#    #+#             */
/*   Updated: 2021/12/13 13:54:58 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Incluimos las librerias esenciales.
*/
#include <iostream>
#include <string.h>
#include <math.h>
#include <limits.h>

struct d_struct
{
	double		value;
	std::string	err;
};

struct i_struct
{
	int			value;
	std::string	err;
};

struct f_struct
{
	float		value;
	std::string	err;
};

struct c_struct
{
	char		value;
	std::string	err;
};

#ifndef CONVERT_H
	#define CONVERT_H
	class Convert
	{
		private:
			std::string value;
			d_struct	d_val;
			i_struct	i_val;
			f_struct	f_val;
			c_struct	c_val;
		public:
			Convert(void);
			Convert(std::string value);
			std::string	getValue(void) const;
			void	setValue(std::string val);
			void	setDoubleVal(double value);
			void	toInt(double val);
			void	setIntVal(int value);
			void	toFloat(double val);
			void	setFloatVal(float value);
			void	toChar(double val);
			void	setCharVal(char value);
			void	setDoubleErr(std::string error);
			void	setIntErr(std::string error);
			void	setFloatErr(std::string error);
			void	setCharErr(std::string error);
			double	getDval(void);
			void	getDoubleVal(void);
			void	getIntVal(void);
			void	getCharVal(void);
			void	getFloatVal(void);
			std::string	getDoubleErr(void);
			std::string	getIntErr(void);
			std::string	getFloatErr(void);
			std::string	getCharErr(void);
			~Convert();
	};
#endif

std::ostream & operator<<(std::ostream & stream , Convert & content);
