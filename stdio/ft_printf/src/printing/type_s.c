/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:34:28 by dthan             #+#    #+#             */
/*   Updated: 2025/05/20 10:53:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../ft_printf.h"
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"

void	type_s(t_info *info, va_list arg, size_t *ct, int fd)
{
	char	*ctemp;
	char	*str;

	ctemp = va_arg(arg, char *);
	if (!ctemp)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(ctemp);
	prec_ctrl_str(info, &str);
	width_ctrl(info, &str);
	write(fd, str, *ct = ft_strlen(str));
	free(str);
}
