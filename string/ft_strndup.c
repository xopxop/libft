/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:18:18 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:10:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utility/ft_utility.h"

char	*ft_strndup(char *str, size_t len)
{
	char	*new;
	int		i;

	new = ft_strnew(len);
	i = 0;
	while (len > 0)
	{
		new[i] = str[i];
		len--;
		i++;
	}
	return (new);
}
