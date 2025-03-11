/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:55:44 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:11:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"
#include "ft_utility.h"

static void copy_data(char *str, char const *s1, char const *s2)
{
	if (s1 && !s2)
		ft_strcpy(str, (char *)s1);
	else if (s2 && !s1)
		ft_strcpy(str, (char *)s2);
	else if (s1 && s2)
	{
		ft_strcpy(str, (char *)s1);
		ft_strcat(str, (char *)s2);
	}
}

static	char *new_str(char const *s1, char const *s2)
{
	size_t	str_size;

	str_size = 0;
	if (s1)
		str_size += ft_strlen(s1);
	if (s2)
		str_size += ft_strlen(s2);
	if (str_size == 0)
		return (NULL);
	return ft_strnew(str_size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = new_str(s1, s2);
	if (!str)
		return (NULL);
	copy_data(str, s1, s2);
	return (str);
}
