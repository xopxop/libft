/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:21:14 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 15:49:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"
#define BASE_DIGITS "0123456789ABCDEF"

/*
** If provide base, it must be 2, 8, 10 or 16
*/

static int	count_digits(unsigned int nb, unsigned int base)
{
	int	ct;

	ct = 1;
	while (nb >= base)
	{
		nb /= base;
		ct++;
	}
	return (ct);
}

char	*ft_uitoa_base(unsigned int nbr, unsigned int base)
{
	char	*str;
	int	index;
	int	str_len;

	if (base != 2 && base != 8 && base != 10 && base != 16)
		return (NULL);
	str_len = count_digits(nbr, base);
	str = ft_strnew(str_len);
	if (!str)
		return (NULL);
	index = str_len - 1;
	while (index >= 0)
	{
		str[index] = BASE_DIGITS[nbr % base];
		nbr /= base;
		index--;
	}
	return (str);
}

char	*ft_uitoa(unsigned int nbr)
{
	return (ft_uitoa_base(nbr, 10));
}

char	*ft_itoa(int signed_nbr)
{
	char		*str;
	unsigned int	unsigned_nbr;
	
	if (signed_nbr == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (signed_nbr < 0)
		unsigned_nbr = (unsigned int)(-signed_nbr);
	else
		unsigned_nbr = (unsigned int)(signed_nbr);
	str = ft_uitoa(unsigned_nbr);
	if (!str)
		return (NULL);
	if (signed_nbr < 0)
		return (ft_strjoin_and_free("-", str, 0, 1));
	return (str);
}
