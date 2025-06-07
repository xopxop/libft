/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.dto.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:55:42 by dthan             #+#    #+#             */
/*   Updated: 2025/05/24 11:30:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INFO_H
# define PARSE_INFO_H
# include "length.enum.h"
# include "specifier.enum.h"
# include "field_width.dto.h"
# include "percision.dto.h"

struct	s_parse_dto
{
	int			flags;
	t_field_width_dto	field_width;
	t_precision_dto		percision;
	t_length		length;
	t_specifier		specifier;
};

typedef struct s_parse_dto	t_parse_dto;

#endif