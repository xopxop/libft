/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:36 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:10:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utility/ft_utility.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = ft_memalloc(size + 1);
	if (!s)
		return (NULL);
	while (i < size)
		s[i++] = '\0';
	return (s);
}
