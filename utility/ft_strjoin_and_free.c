/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 08:09:40 by dthan             #+#    #+#             */
/*   Updated: 2025/03/11 14:12:06 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_utility.h"

char *ft_strjoin_and_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if (!result)
		return (NULL);
	if (free_s1 && s1)
		free(s1);
	if (free_s2 && s2)
		free(s2);
	return (result);
}
