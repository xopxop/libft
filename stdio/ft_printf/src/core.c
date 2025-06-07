/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 02:33:13 by dthan             #+#    #+#             */
/*   Updated: 2025/05/21 09:12:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "../ft_printf.h"
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"

int	parse_and_print(const char *format, va_list args, size_t *pos, int fd)
{
	t_info	info;
	int		position_copy;
	// char	*str;

	position_copy = *pos;
	if (format[*pos] == '\0')
		return (0);
	parsing(format, args, pos, &info);
	if (info.specifier == spec_none)
	{
		// if (args)
		// {
		// 	*pos = position_copy + 1;
		// 	str = ft_itoa_signed_longlong((long long)info.dup_first_args);
		// 	write(fd, "%", 1);
		// 	write(fd, str, ft_strlen(str));
		// 	free(str);
		// 	return (ft_strlen(str) + 2);
		// }
		*pos = position_copy;
		write(fd, "%", 1);
		return (0);
	}
	return (printing(&info, args, fd));
}

int	full_str_printing(const char *format, va_list args, int fd)
{
	size_t	pos;
	int		len;
	int		spurious_traling_case;

	pos = 0;
	len = 0;
	spurious_traling_case = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
		{
			write(fd, &format[pos++], 1);
			len++;
		}
		else
		{
			pos++;
			len += parse_and_print(format, args, &pos, fd);
			if (len < spurious_traling_case)
				return (-1);
		}
		spurious_traling_case = len;
	}
	return (len);
}

int	full_str_printing(const char *format, va_list args, int fd)
{
	size_t	pos;
	int		len;
	int		spurious_traling_case;

	pos = 0;
	len = 0;
	spurious_traling_case = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
		{
			write(fd, &format[pos++], 1);
			len++;
		}
		else
		{
			pos++;
			len += parse_and_print(format, args, &pos, fd);
			if (len < spurious_traling_case)
				return (-1);
		}
		spurious_traling_case = len;
	}
	return (len);
}