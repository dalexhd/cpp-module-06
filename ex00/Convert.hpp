/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:15:33 by aborboll          #+#    #+#             */
/*   Updated: 2021/12/14 12:13:05 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Incluimos las librerias esenciales.
*/
#include <iostream>
#include <string.h>
#include <cmath>
#include <limits.h>

template <typename T>
struct holder
{
	T		value;
	std::string	err;
};

#ifndef CONVERT_H
	#define CONVERT_H
	class Convert
	{
		private:
			std::string value;
			holder<double>	d_val;
			holder<int>		i_val;
			holder<float>	f_val;
			holder<char>	c_val;
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
