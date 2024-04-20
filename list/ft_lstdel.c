/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:05:31 by dthan             #+#    #+#             */
/*   Updated: 2024/04/21 00:13:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** ft_lstdel(t_list **alst, void (*del)(void *, size_t))
** DESCRIPTION: Take as a parameter the adress of a pointer to a link and frees
** the memory of this link and every successor of that link using the functions
** del and frees(3). Finally the pointer to the link that was just freed must
** be set to NULL (quite similar to the fucntion ft_memdel from the mandatory
** part).
** PARAM#1. The Adress of a pointer to the first link of a list that needs
** to be freed.
** RETURN VALUE: None.
** Libc function: free(3).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && *del)
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
