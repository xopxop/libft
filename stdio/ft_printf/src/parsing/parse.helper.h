/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:23:55 by dthan             #+#    #+#             */
/*   Updated: 2025/06/07 18:28:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HELPER_H
# define PARSE_HELPER_H
#include <stdarg.h>
#include "./models/width.dto.h"
#include "./models/percision.dto.h"
#include "./models/length.enum.h"
#include "./models/specifier.enum.h"

int		get_flags(const char *format, int *index);
t_width_dto	get_width(const char *format, va_list args, int *index);
t_precision_dto	get_precision(const char *format, va_list args, int *index);
t_length	get_length(const char *format, int *index);
t_specifier	get_specifier(const char *format, int *index);

#endif