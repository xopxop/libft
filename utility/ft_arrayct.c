/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 13:36:33 by dthan             #+#    #+#             */
/*   Updated: 2026/05/29 09:46:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_arrayct(char **str_array)
{
	int		count;
	char	**ptr;

	count = 0;
	ptr = str_array;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	return (count);
}
