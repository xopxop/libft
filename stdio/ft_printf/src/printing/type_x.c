/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:31:21 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 13:39:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "print.dto.h"
#include "parse.dto.h"
#include "../utility/ft_utility.h"

// #define HEX_MASK 15
// #define SHIFF_HEX_MASK 4

// void	small_x(t_info *info, va_list arg, char **output)
// {
// 	unsigned long long	num;
// 	char				*str;
// 	char				*hex;

// 	hex = "0123456789abcdef";
// 	num = get_unsigned_argument(info, arg);
// 	str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, hex);
// 	flag_ignore(info, str);
// 	prec_ctrl_oct_hex(info, &str);
// 	flag_control(info, &str, 0);
// 	width_ctrl(info, &str);
// 	*output = str;
// }

// void	big_x(char **output)
// {
// 	char	*new;

// 	new = *output;
// 	while (*new)
// 	{
// 		*new = ft_toupper(*new);
// 		new++;
// 	}
// }

// void	type_x(t_info *info, va_list arg, size_t *ct, int fd)
// {
// 	char	*output;

// 	small_x(info, arg, &output);
// 	if (info->specifier == spec_hexupcase)
// 		big_x(&output);
// 	write(fd, output, *ct = ft_strlen(output));
// 	free(output);
// }


static char	*apply_formatting(unsigned int nbr, t_parse_dto parse_dto, int lower_case)
{
	char *str;

	str = ft_uitoa_base(nbr, 16);
	if (!str)
		return (NULL);
	str = precision_integer(parse_dto.percision, str);
	if (!str)
		return (NULL);
	str = flag_control(parse_dto.flags, str);
	if (!str)
		return (NULL);
	str = field_width_control(parse_dto.field_width, str);
	if (!str)
		return (NULL);
	if (lower_case)
		lower_case_str(str);
	return (str);
}

t_print_dto	*type_x(t_parse_dto parse_dto, va_list arg, int lower_case)
{
	unsigned int	nbr;
	char		*formatted_str;

	nbr = va_arg(arg, unsigned int);
	formatted_str = apply_formatting(nbr, parse_dto, lower_case);
	if (!formatted_str)
		return (NULL);
	return (new_print_dto(formatted_str, ft_strlen(formatted_str)));	
}
