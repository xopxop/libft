/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:01:32 by dthan             #+#    #+#             */
/*   Updated: 2024/04/21 00:28:04 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putendl(char const *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
