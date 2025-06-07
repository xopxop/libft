/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:43:51 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 13:54:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "print.dto.h"
#include "parse.dto.h"
#include "../utility/ft_utility.h"
#include "flag.enum.h"

// void	type_di(t_info *info, va_list arg, size_t *ct, int fd)
// {
// 	long long	num;
// 	char		*str;
// 	int			negative;

// 	negative = 0;
// 	num = get_signed_argument(info, arg);
// 	if (num < 0)
// 		negative = 1;
// 	str = ft_itoa_signed_longlong(num);
// 	flag_ignore(info, str);
// 	prec_ctrl_nums(info, &str, negative);
// 	flag_control(info, &str, negative);
// 	width_ctrl(info, &str);
// 	write(fd, str, *ct = ft_strlen(str));
// 	free(str);
// }

int	get_output_len(int field_width, int str_len)
{
	if (field_width > str_len)
		return (field_width);
	return (str_len);
}

char	*flag_control_integer(int flags, char *str, int negative)
{

}

char	*field_width_control(t_field_width_dto field_width, char *str, int align_left, char pad_char)
{
	int len;
	int pad;
	char *new_str;

	if (!field_width.specified)
		return (str);
	len = ft_strlen(str);
	pad = field_width.value - len;
	if (pad <= 0)
		return (str);
	new_str = ft_strnew(field_width.value);
	if (!new_str)
		return (NULL);
	ft_memset(new_str, pad_char, pad);	
	if (align_left)
		ft_strcpy(new_str + pad, str);
	else
		ft_strcpy(new_str, str);
	free(str);
	return (new_str);
}

static char *apply_formatting(long long nbr, t_parse_dto dto)
{
	char *str;
	
	str = ft_lltoa(nbr);
	if (!str)
		return (NULL);
	str = precision_control_decimal(dto.percision, str, nbr < 0);
	if (!str)
		return (NULL);
	str = falg_control(dto.flags, str, nbr < 0);
	if(!str)
		return (NULL);
	str = field_width_control( \
		dto.field_width, \
		str, \
		dto.flags & left_align, \
		(dto.flags & pad_with_zero) ? '0' : ' ' \
	);
	return (str);
}

t_print_dto *type_di(t_parse_dto parse_dto, va_list arg)
{
	long long	nbr;
	char		*formatted_str;
	t_print_dto	*print_dto;

	nbr = get_signed_nbr(parse_dto.length, arg);
	formatted_str = apply_formatting(nbr, parse_dto);
	if (!formatted_str)
		return (NULL);
	print_dto = new_print_dto(formatted_str, ft_strlen(formatted_str));
	return (print_dto);
}
