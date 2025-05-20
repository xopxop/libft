/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:52:04 by dthan             #+#    #+#             */
/*   Updated: 2025/05/20 10:44:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include "../ctype/ft_ctype.h"

/*
** ft_skip_atoi will take the number from the string
** Return value: the number from the str
*/

int	ft_skip_atoi(const char *format, size_t *pos)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[*pos]))
		i = i * 10 + format[(*pos)++] - '0';
	return (i);
}

int	ft_isspecifier(char specifier)
{
	char	*list_specifier;

	list_specifier = "cspdiuoxXf%";
	while (*list_specifier)
	{
		if (specifier == *list_specifier)
			return (1);
		list_specifier++;
	}
	return (0);
}

int	ft_isflag(char chr)
{
	char	*list_flags;

	list_flags = "-+ #0";
	while (*list_flags)
	{
		if (*list_flags == chr)
			return (1);
		list_flags++;
	}
	return (0);
}
