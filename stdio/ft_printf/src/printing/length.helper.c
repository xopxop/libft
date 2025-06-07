/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 05:57:46 by dthan             #+#    #+#             */
/*   Updated: 2025/05/23 06:06:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "length.enum.h"

/*
** the function get_signed_argument is for signed integer (type i & d)
** it will return the value which is respectively to the flags length
** length:  h(short) -
**          hh(signed char)
**          l (long int)
**          ll (long long int)
** for more info: http://www.cplusplus.com/reference/cstdio/printf/
*/

long long	get_signed_nbr(t_length length, va_list arg)
{
	long long	num;

	if (length == len_h)
		num = (short)va_arg(arg, int);
	else if (length == len_hh)
		num = (char)va_arg(arg, int);
	else if (length == len_l)
		num = (long)va_arg(arg, long);
	else if (length == len_ll)
		num = (long long)va_arg(arg, long long);
	else
		num = (int)va_arg(arg, int);
	return (num);
}

/*
** the function get_unsigned_arument is for unsigned interger (type u)
** the return value is rescpectively to the length
** http://www.cplusplus.com/reference/cstdio/printf/
*/

unsigned long long	get_unsigned_nbr(t_length length, va_list arg)
{
	unsigned long	num;

	if (length == len_h)
		num = (unsigned short)va_arg(arg, unsigned int);
	else if (length == len_hh)
		num = (unsigned char)va_arg(arg, unsigned int);
	else if (length == len_l)
		num = (unsigned long)va_arg(arg, unsigned long);
	else if (length == len_ll)
		num = (unsigned long long)va_arg(arg, unsigned long long);
	else
		num = (unsigned int)va_arg(arg, unsigned int);
	return (num);
}
