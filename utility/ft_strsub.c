/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:36:03 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:10:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utility/ft_utility.h"

char	*ft_strsub(char const *string, unsigned int start, size_t len)
{
	char	*substring;

	if (!string)
		return (NULL);
	substring = ft_memalloc(len + 1);
	if (!substring)
		return (NULL);
	substring = ft_strncpy(substring, (char *)string + start, len);
	return (substring);
}
