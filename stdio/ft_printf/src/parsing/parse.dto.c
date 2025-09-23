/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.dto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:00:57 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 18:30:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./parse.dto.h"
#include "./parse.helper.h"

void	parse_dto_init(t_parse_dto *dto)
{
	dto->flags = 0;
	dto->width.specified = 0;
	dto->width.value = 0;
	dto->percision.specified = 0;
	dto->percision.value = 0;
	dto->length = len_none;
	dto->specifier = spec_none;
}

void	parse_dto_parse(t_parse_dto *dto, const char *format, va_list args, int *index)
{
	parse_dto_init(dto);
	dto->flags = get_flags(format, index);
	dto->width = get_width(format, args, index);
	dto->percision = get_precision(format, args, index);
	dto->length = get_length(format, index);
	dto->specifier = get_specifier(format, index);
}
