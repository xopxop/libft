/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:01:44 by dthan             #+#    #+#             */
/*   Updated: 2025/05/20 10:53:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../ft_printf.h"
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"

void	type_u(t_info *info, va_list arg, size_t *ct, int fd)
{
	unsigned long long	num;
	char				*str;

	num = get_unsigned_argument(info, arg);
	str = ft_itoa_unsigned_longlong(num);
	flag_ignore(info, str);
	prec_ctrl_nums(info, &str, 0);
	flag_control(info, &str, 0);
	width_ctrl(info, &str);
	write(fd, str, *ct = ft_strlen(str));
	free(str);
}
