/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:33:24 by dthan             #+#    #+#             */
/*   Updated: 2025/06/09 04:53:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parse.dto.h"
#include "print.dto.h"
#include "flag.enum.h"

// void	type_c(t_info *info, va_list arg, size_t *ct, int fd)
// {
// 	char	chr;
// 	char	*str;
// 	int		null;
// 	int		null_position;

// 	null_position = 0;
// 	chr = va_arg(arg, char);
// 	str = ft_strnew(1);
// 	if (chr == '\0')
// 		null = 1;
// 	else
// 		null = 0;
// 	str[0] = chr + null;
// 	width_ctrl(info, &str);
// 	*ct = ft_strlen(str);
// 	if (null)
// 	{
// 		while (str[null_position] != chr + null)
// 			null_position++;
// 		str[null_position] = 0;
// 	}
// 	write(fd, str, *ct);
// 	free(str);
// }

static int	get_output_len(int field_width, int str_len)
{
	if (field_width > str_len)
		return (field_width);
	return (str_len);
}

static char	*get_output_str(int flags, int dst_len, char *src, int src_len)
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

static char *apply_formatting(char chr, t_parse_dto parse_dto)
{
	char *str;

	
}

t_print_dto	*type_c(t_parse_dto parse_dto, va_list arg)
{
	t_print_dto	*print_dto;
	char		chr;

	chr = va_arg(arg, int);
	print_dto = new_print_dto();
	print_dto->len = get_output_len(parse_dto.field_width, 1);
	print_dto->str = get_output_str(parse_dto.flags, print_dto->len, (char[]){ chr, '\0' });
	return (print_dto);
}
