/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:56:47 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 17:35:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utility/ft_utility.h"
#include "../string/ft_string.h"

char	*ft_strmap(char const *string, char (*f)(char))
{
	char	*newstring;
	char	*pstring;
	char	*pnewstring;

	if (!string || !f)
		return (NULL);
	newstring = ft_memalloc((size_t)ft_strlen((char *)string) + 1);
	if (!newstring)
		return (NULL);
	pstring = (char *)string;
	pnewstring = newstring;
	while (*pstring)
		*(pnewstring++) = f(*(pstring++));
	return (newstring);
}
