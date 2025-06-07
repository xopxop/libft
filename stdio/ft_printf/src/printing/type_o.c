/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:51:30 by dthan             #+#    #+#             */
/*   Updated: 2025/06/06 15:44:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "print.dto.h"
#include "parse.dto.h"
#include "../utility/ft_utility.h"

#define OCTAL_MASK 7
#define SHIFF_OCTAL_MASK 3

// void	type_o(t_info *info, va_list arg, size_t *ct, int fd)
// {
// 	unsigned long long	num;
// 	char				*str;
// 	char				*oct;

// 	oct = "01234567";
// 	num = get_unsigned_argument(info, arg);
// 	str = ft_number_conversion(num, OCTAL_MASK, SHIFF_OCTAL_MASK, oct);
// 	flag_ignore(info, str);
// 	prec_ctrl_oct_hex(info, &str);
// 	flag_control(info, &str, 0);
// 	width_ctrl(info, &str);
// 	write(fd, str, *ct = ft_strlen(str));
// 	free(str);
// }

static char	*apply_formatting(unsigned int nbr, t_parse_dto parse_dto)
{
	char *str;

	str = ft_uitoa_base(nbr, 8);
	if (!str)
		return (NULL);
	str = precison_control_integer(parse_dto.percision, str, 0);
	if (!str)
		return (NULL);
	str = flag_control();
	if (!str)
		return (NULL);
	str = field_width_control();
	return (str);
}

t_print_dto *type_o(t_parse_dto parse_dto, va_list arg)
{
	unsigned int	nbr;
	char		*formatted_str;

	nbr = va_arg(arg, unsigned int);
	formatted_str = apply_formatting(nbr, parse_dto);
	if (!formatted_str)
		return (NULL);
	return (new_print_dto(formatted_str, ft_strlen(formatted_str)));
}
