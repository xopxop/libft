/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 08:08:13 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 15:51:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"
#define BASE_DIGITS "0123456789ABCDEF"

/*
** Only correct to handle 64bit system
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

char	*ft_ulltoa_base(unsigned long long nbr, unsigned int base)
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

char	*ft_ulltoa(unsigned long long nbr)
{
	return (ft_ulltoa_base(nbr, 10));
}

char	*ft_lltoa(long long signed_nbr)
{
	char			*str;
	unsigned long long	unsigned_nbr;

	if (signed_nbr == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (signed_nbr < 0)
		unsigned_nbr = (unsigned long long)(-signed_nbr);
	else
		unsigned_nbr = (unsigned long long)(signed_nbr);
	str = ft_ulltoa(unsigned_nbr);
	if (!str)
		return (NULL);
	if (signed_nbr < 0)
		return (ft_strjoin_and_free("-", str, 0, 1));
	return (str);
}