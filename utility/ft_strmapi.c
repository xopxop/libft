/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:58:25 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:10:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utility/ft_utility.h"

char	*ft_strmapi(char const *string, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*newstring;

	index = 0;
	if (!string || !f)
		return (NULL);
	newstring = ft_memalloc((size_t)ft_strlen((char *)string) + 1);
	if (!newstring)
		return (NULL);
	while (string[index])
	{
		newstring[index] = f(index, string[index]);
		index++;
	}
	return (newstring);
}
