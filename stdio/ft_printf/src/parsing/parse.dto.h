/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.dto.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:55:42 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 16:08:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INFO_H
# define PARSE_INFO_H
# include "./models/width.dto.h"
# include "./models/percision.dto.h"
# include "./models/length.enum.h"
# include "./models/specifier.enum.h"

struct	s_parse_dto
{
	int			flags;
	t_width_dto		width;
	t_precision_dto		percision;
	t_length		length;
	t_specifier		specifier;
};

typedef struct s_parse_dto	t_parse_dto;

void	parse_dto_init(t_parse_dto *dto);

#endif