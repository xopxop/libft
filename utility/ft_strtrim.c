/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:25:48 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:11:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utility/ft_utility.h"

char	*ft_strtrim(char const *string)
{
	int	stringstart;
	int	stringend;

	stringstart = 0;
	if (!string)
		return (NULL);
	stringend = ft_strlen((char *)string);
	while (ft_isspace(string[stringstart]))
		stringstart++;
	while (ft_isspace(string[stringend - 1]))
		stringend--;
	if (stringend < stringstart)
		stringend = stringstart;
	return (ft_strsub(string, stringstart, stringend - stringstart));
}
