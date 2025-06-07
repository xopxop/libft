/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:55:35 by dthan             #+#    #+#             */
/*   Updated: 2025/05/22 08:00:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "output.h"
#include "../../../utility/ft_utility.h"

t_output *new_output()
{
	t_output *obj;

	obj = malloc(sizeof(t_output));
	obj->str = NULL;
	obj->len = 0;
	return (obj);
}
