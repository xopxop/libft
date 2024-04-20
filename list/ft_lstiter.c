/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:56:21 by dthan             #+#    #+#             */
/*   Updated: 2024/04/21 00:10:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.interface.h"

/*
** ft_lstiter
** PROTOTYPE: void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
** DESCRIPTION: Iterates the list lst and applies the fuction f to each link.
** PARAMS.#1: A pointer to the first link of a list.
** PARAMS.#2: The address of a function to apply to each link of a list.
** RETURN VALUE: None.
** Libc FUNCTIONS: None.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
