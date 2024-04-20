/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:27:03 by dthan             #+#    #+#             */
/*   Updated: 2024/04/21 00:28:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putstr_fd(char const *str, int fd)
{
	int	index;

	index = 0;
	while (str[index])
	{
		ft_putchar_fd(str[index], fd);
		index++;
	}
}
