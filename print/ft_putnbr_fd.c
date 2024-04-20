/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:48:02 by dthan             #+#    #+#             */
/*   Updated: 2024/04/21 00:22:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	unsigned int	nb;

	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned int)(nbr * -1);
	}
	else
		nb = (unsigned int)nbr;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
