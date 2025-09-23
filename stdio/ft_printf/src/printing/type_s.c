/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:34:28 by dthan             #+#    #+#             */
/*   Updated: 2025/06/09 04:53:23 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parse.dto.h"
#include "print.dto.h"


// void	type_s(t_info *info, va_list arg, size_t *ct, int fd)
// {
// 	char	*ctemp;
// 	char	*str;

// 	ctemp = va_arg(arg, char *);
// 	if (!ctemp)
// 		str = ft_strdup("(null)");
// 	else
// 		str = ft_strdup(ctemp);
// 	prec_ctrl_str(info, &str);
// 	width_ctrl(info, &str);
// 	write(fd, str, *ct = ft_strlen(str));
// 	free(str);
// }

#include <stdlib.h>

static char	*apply_formatting(char *str, t_parse_dto parse_dto)
{
	char *formatted_str;

	if (!str)
		formatted_str = ft_strdup("(null)");
	else
		formatted_str = ft_strdup(str);
	if (!formatted_str)
		return (NULL);
	formatted_str = precision_string(parse_dto.percision, formatted_str);
	if (!formatted_str)
		return (NULL);
	formatted_str = field_width_control(parse_dto.field_width, formatted_str);
	return (formatted_str);
}

t_print_dto	*type_s(t_parse_dto parse_dto, va_list arg)
{
	char	*arg_str;
	char	*formatted_str;

	arg_str = va_arg(arg, char *);
	formatted_str = apply_formatting(arg_str, parse_dto);
	if (!formatted_str)
		return (NULL);
	return (new_print_dto(formatted_str, ft_strlen(formatted_str)));
}
