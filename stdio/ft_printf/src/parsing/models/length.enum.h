/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 06:01:00 by dthan             #+#    #+#             */
/*   Updated: 2025/05/24 10:59:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGTH_ENUM_H
# define LENGTH_ENUM_H

enum	e_length
{
	len_hh,
	len_h,
	len_ll,
	len_l,
	len_lup,
	len_none,
};

typedef enum e_length	t_length;

#endif
