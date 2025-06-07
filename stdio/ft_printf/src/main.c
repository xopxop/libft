/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:08:52 by dthan             #+#    #+#             */
/*   Updated: 2025/05/21 09:05:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int	len;
	va_list	args;

	va_start(args, format);
	len = full_str_printing(format, args, STDOUT_FILENO);
	va_end(args);
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int	len;
	va_list	args;

	va_start(args, format);
	len = full_str_printing(format, args, fd);
	va_end(args);
	return (len);
}
