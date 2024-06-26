/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:50:37 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 14:13:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *str)
{
	int index;

	if (str) {
		index = 0;
		while (str[index])
		{
			str[index] = '\0';
			index++;
		}
	}
}
