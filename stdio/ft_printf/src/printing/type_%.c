/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_%.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:35:36 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 18:42:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "print.dto.h"
#include "parse.dto.h"
#include "flag.enum.h"

// void	type_percent(t_info *info, __attribute__((unused)) va_list arg, \
// 		size_t *ct, int fd)
// {
// 	char	percent;
// 	char	*str;

// 	percent = '%';
// 	str = ft_strnew(1);
// 	str[0] = percent;
// 	width_ctrl(info, &str);
// 	write(fd, str, *ct = ft_strlen(str));
// 	free(str);
// }

static int	get_len(int field_width, int str_len)
{
	if (field_width > str_len)
		return (field_width);
	return (str_len);
}

static char	*get_str(int flags, int dst_len, char *src, int src_len)
{
	char	*dst;

	dst = ft_strnew(dst_len);
	if (flags & left_align)
	{
		ft_memcpy(dst, src, src_len);
		ft_memset(dst + src_len, ' ', dst_len - src_len);
	}
	else if (flags & pad_with_zero)
	{
		ft_memset(dst, '0', dst_len - src_len);
		ft_memcpy(dst + dst_len - src_len, src, src_len);
	}
	else
	{
		ft_memset(dst, ' ', dst_len - src_len);
		ft_memcpy(dst + dst_len - src_len, src, src_len);
	}
	return (dst);
}

t_print_dto *type_percent(t_parse_dto parse_dto, va_list arg)
{
	t_print_dto *print_dto;

	print_dto = new_print_dto();
	print_dto->len = get_len(parse_dto.field_width, 1);
	print_dto->str = get_str(parse_dto.flags, print_dto->len, "%", 1);
	return (print_dto);
}
