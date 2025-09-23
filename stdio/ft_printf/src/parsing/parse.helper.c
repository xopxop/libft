/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:38:41 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 18:39:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./models/flag.enum.h"
#include "./models/width.dto.h"
#include "./models/percision.dto.h"
#include "./models/length.enum.h"
#include "./models/specifier.enum.h"
#include "../../string/ft_string.h"

/*
** the ft parsing flags will pare the flags at the position of the string format
** using bitwise operand to store flags
** NOTE: Also, using loop ft to keep parsing flags
*/

// void	get_flags(const char *format, size_t *pos, t_info *info)
// {
// 	while (ft_isflag(format[*pos]))
// 	{
// 		if (format[*pos] == '-')
// 			info->flags |= MINUS_SIGN;
// 		else if (format[*pos] == '+')
// 			info->flags |= PLUS_SIGN;
// 		else if (format[*pos] == ' ')
// 			info->flags |= SPACE;
// 		else if (format[*pos] == '#')
// 			info->flags |= HASH_SIGN;
// 		else if (format[*pos] == '0')
// 			info->flags |= ZERO;
// 		(*pos)++;
// 	}
// }

int	get_flags(const char *format, int *index)
{
	int flags;

	flags = 0;
	while (ft_strchr("-+ #0", format[*index]))
	{
		if (format[*index] == '-')
			flags |= left_align;
		else if (format[*index] == '+')
			flags |= plus_sign;
		else if (format[*index] == ' ')
			flags |= space;
		else if (format[*index] == '#')
			flags |= hash_sign;
		else if (format[*index] == '0')
			flags |= pad_with_zero;
		(*index)++;
	}
	return (flags);
}

/*
** same like ft get_percision, it will take the number or the argument then put
** it into the int field_width of the struct into
** However, there is a note here, if the argument is < 0 (ex: -10...)
** we regconize there is a minus flag here and using OR bitwise operand to store
** the minus sign flag
*/

// void	get_width(const char *format, size_t *pos, va_list arg, \
// 		t_info *info)
// {
	
// 	while (ft_isdigit(format[*pos]) || format[*pos] == '*')
// 	{
// 		if (ft_isdigit(format[*pos]))
// 			info->field_width = ft_skip_atoi(format, pos);
// 		else if (format[*pos] == '*')
// 		{
// 			(*pos)++;
// 			info->field_width = va_arg(arg, int);
// 			info->dup_first_args = info->field_width;
// 			if (info->field_width < 0)
// 			{
// 				info->field_width *= -1;
// 				info->flags |= MINUS_SIGN;
// 			}
// 		}
// 	}
// }

t_width_dto	get_width(const char *format, va_list arg, int *index)
{
	t_width_dto dto;

	ft_bzero(&dto, sizeof(t_width_dto));
	if (ft_isdigit(format[*index]))
	{
		dto.specified = 1;
		while (ft_isdigit(format[*index]))
		{
			dto.value = dto.value * 10 + format[(*index)] - '0';
			(*index)++;
		}
	}
	else if (format[*index] == '*')
	{
		dto.specified = 1;
		dto.value = va_arg(arg, int);
		(*index)++;
	}
	return (dto);
}

/*
** get_percision ft will parese the percision then put the result into the int
** percision in the info struct
** If at the position of the format string is digit, using ft_skip_atoi to take
** the digit in the format string and covert it into interger
** If there is an argument/va_list with the format[*position] == '*'
** the int percision will take the argument instead
*/

// void	get_precision(const char *format, size_t *pos, va_list arg, \
// 		t_info *info)
// {
// 	if (format[*pos] == '.')
// 	{
// 		(*pos)++;
// 		if (ft_isdigit(format[*pos]))
// 			info->percision = ft_skip_atoi(format, pos);
// 		else if (format[*pos] == '*')
// 		{
// 			(*pos)++;
// 			info->percision = va_arg(arg, int);
// 			if (info->dup_first_args != 0)
// 				info->dup_first_args = info->percision;
// 		}
// 		else
// 			info->percision = 0;
// 	}
// }

t_precision_dto	get_precision(const char *format, int *index, va_list arg)
{
	t_precision_dto dto;

	ft_bzero(&dto, sizeof(t_precision_dto));
	if (format[*index] == '.')
	{
		dto.specified = 1;
		(*index)++;
		if (ft_isdigit(format[*index]))
		{
			while (ft_isdigit(format[*index]))
			{
				dto.value = dto.value * 10 + format[(*index)] - '0';
				(*index)++;
			}
		}
		else if (format[*index] == '*')
		{
			(*index)++;
			dto.value = va_arg(arg, int);
		}
		else
			dto.value = 0;
	}
	return (dto);
}

/*
** get_length function will parse the length/ conversion qualifier then put
** the result into t_length of the struc info
** 'h' --> len_h
** "hh" --> len_hh
** 'l' --> len_l
** 'll' -->len_ll
** 'L' -->len_lup
** nothing -->len_none
*/

// void	get_length(const char *format, size_t *pos, t_info *info)
// {
// 	if ((format[*pos] == 'l' && format[*pos + 1] == 'l') || \
// 			(format[*pos] == 'h' && format[*pos + 1] == 'h'))
// 	{
// 		if (format[*pos + 1] == 'l')
// 			info->length = len_ll;
// 		else
// 			info->length = len_hh;
// 		*pos += 2;
// 	}
// 	else if (format[*pos] == 'h' || format[*pos] == 'l' || \
// 			format[*pos] == 'L')
// 	{
// 		if (format[*pos] == 'h')
// 			info->length = len_h;
// 		else if (format[*pos] == 'l')
// 			info->length = len_l;
// 		else if (format[*pos] == 'L')
// 			info->length = len_lup;
// 		(*pos)++;
// 	}
// }

t_length get_length(const char *format, int *index)
{
	t_length length;

	length = len_none;
	if (format[*index] == 'l' && format[*index + 1] == 'l')
	{
		length = len_ll;
		*index += 2;
	}
	else if (format[*index] == 'h' && format[*index + 1] == 'h')
	{
		length = len_hh;
		*index += 2;
	}
	else if (format[*index] == 'h')
	{
		length = len_h;
		(*index)++;
	}
	else if (format[*index] == 'l')
	{
		length = len_l;
		(*index)++;
	}
	else if (format[*index] == 'L')
	{
		length = len_lup;
		(*index)++;
	}
	return (length);
}

/*
** Ft get_specifier will take the format string at the position to parse then
** put the result into t_specifier in the struc info
** If:
** 'c' --> character
** 's' --> string
** 'p' --> Address
** 'd' || 'i' --> signed decimal interger
** 'u' --> unsigned decimal interger
** 'x' || 'X' --> unsigned hexadecimal interger lower/ upper case
** 'o' --> unsigned octal
** 'f' --> decimal floating point (lower case)
** '%' --> percentage sign
*/

// void	get_specifier(const char *format, size_t *pos, t_info *info)
// {
// 	if (ft_isspecifier(format[*pos]))
// 	{
// 		if (format[*pos] == 'c')
// 			info->specifier = spec_char;
// 		else if (format[*pos] == 's')
// 			info->specifier = spec_str;
// 		else if (format[*pos] == 'p')
// 			info->specifier = spec_ptr;
// 		else if (format[*pos] == 'd' || format[*pos] == 'i')
// 			info->specifier = spec_int;
// 		else if (format[*pos] == 'u')
// 			info->specifier = spec_uint;
// 		else if (format[*pos] == 'o')
// 			info->specifier = spec_octal;
// 		else if (format[*pos] == 'x')
// 			info->specifier = spec_hexlowcase;
// 		else if (format[*pos] == 'X')
// 			info->specifier = spec_hexupcase;
// 		else if (format[*pos] == 'f')
// 			info->specifier = spec_float;
// 		else if (format[*pos] == '%')
// 			info->specifier = spec_percentsign;
// 		(*pos)++;
// 	}
// }

t_specifier	get_specifier(const char *format, int *index)
{
	if (!ft_strchr("cspdiuoxXf%", format[*index]))
		return (spec_none);
	(*index)++;
	if (format[*index - 1] == 'c')
		return (spec_char);
	if (format[*index - 1] == 's')
		return (spec_str);
	if (format[*index - 1] == 'p')
		return (spec_ptr);
	if (format[*index - 1] == 'd' || format[*index - 1] == 'i')
		return (spec_int);
	if (format[*index - 1] == 'u')
		return (spec_uint);
	if (format[*index - 1] == 'o')
		return (spec_octal);
	if (format[*index - 1] == 'x')
		return (spec_hexlowcase);
	if (format[*index - 1] == 'X')
		return (spec_hexupcase);
	if (format[*index - 1] == 'f')
		return (spec_float);
	return (spec_percentsign);
}
