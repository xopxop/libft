/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.enum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:51:38 by dthan             #+#    #+#             */
/*   Updated: 2025/05/24 10:54:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_ENUM_H
# define FLAG_ENUM_H

typedef enum e_flag
{
	left_align = 1 << 0,
	pad_with_zero = 1 << 1,
	plus_sign = 1 << 2,
	space = 1 << 3,
	hash_sign = 1 << 4,
}	t_flag;

#endif