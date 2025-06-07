/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.dto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:27:56 by dthan             #+#    #+#             */
/*   Updated: 2025/05/24 11:29:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_WIDTH_DTO_H
# define FIELD_WIDTH_DTO_H

struct  s_field_width_dto
{
	int	specified;
	int	value;
};

typedef struct s_field_width_dto	t_field_width_dto;

#endif