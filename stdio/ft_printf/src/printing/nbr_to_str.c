/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:56:46 by dthan             #+#    #+#             */
/*   Updated: 2025/05/23 06:03:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"
#define MAXLEN 23

char	*ft_number_conversion(unsigned long long num, int mask, \
		int shiff_nbr, char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ft_memalloc(MAXLEN);
	if (!str)
		return (NULL);
	if (num == 0)
		ft_strcpy(str, "0");
	else
	{
		while (num)
		{
			str[i++] = s[num & mask];
			num >>= shiff_nbr;
		}
		str = ft_strrev(str);
	}
	return (str);
}
