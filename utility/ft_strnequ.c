/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:59:32 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 17:35:44 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"

int	ft_strnequ(char const *string1, char const *string2, size_t maxlen)
{
	if (!string1 || !string2)
		return (0);
	if (ft_strncmp(string1, string2, maxlen))
		return (0);
	return (1);
}
