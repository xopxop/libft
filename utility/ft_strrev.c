/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:26:45 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:12:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utility/ft_utility.h"

char	*ft_strrev(char *str)
{
	char	ch;
	int		i;
	int		j;

	i = (int)ft_strlen(str) - 1;
	j = 0;
	while (i > j)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i--;
		j++;
	}
	return (str);
}
