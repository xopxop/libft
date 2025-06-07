/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:01:44 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 13:47:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../ft_printf.h"
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"
#include "flag.enum.h"

// void	type_u(t_info *info, va_list arg, size_t *ct, int fd)
// {
// 	unsigned long long	num;
// 	char				*str;

// 	num = get_unsigned_argument(info, arg);
// 	str = ft_itoa_unsigned_longlong(num);
// 	flag_ignore(info, str);
// 	prec_ctrl_nums(info, &str, 0);
// 	flag_control(info, &str, 0);
// 	width_ctrl(info, &str);
// 	write(fd, str, *ct = ft_strlen(str));
// 	free(str);
// }

#include "print.dto.h"
#include "parse.dto.h"
#include "va_arg.helper.h"

static char *apply_formatting(unsigned long long nbr, t_parse_dto dto)
{
	char *str;
	
	str = ft_ulltoa(nbr);
	if (!str)
		return (NULL);
	str = precision_control_decimal(dto.percision, str, 0);
	if (!str)
		return (NULL);
	str = falg_control(dto.flags, str, 0);
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


t_print_dto	*type_u(t_parse_dto parse_dto, va_list arg)
{
	unsigned long long	nbr;
	char			*formatted_str;

	nbr = get_unsigned_nbr(parse_dto.length, arg);
	formatted_str = apply_formatting(nbr, parse_dto);
	if (!formatted_str)
		return (NULL);
	return (new_print_dto(formatted_str, ft_strlen(formatted_str)));
}