/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:38:01 by dthan             #+#    #+#             */
/*   Updated: 2026/05/29 09:32:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.interface.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	newlst->next = ft_lstmap(lst->next, f);
	return (newlst);
}
