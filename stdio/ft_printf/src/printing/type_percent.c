/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:35:36 by dthan             #+#    #+#             */
/*   Updated: 2025/05/20 10:54:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../ft_printf.h"
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"

void	type_percent(t_info *info, __attribute__((unused)) va_list arg, \
		size_t *ct, int fd)
{
	char	percent;
	char	*str;

	percent = '%';
	str = ft_strnew(1);
	str[0] = percent;
	width_ctrl(info, &str);
	write(fd, str, *ct = ft_strlen(str));
	free(str);
}
