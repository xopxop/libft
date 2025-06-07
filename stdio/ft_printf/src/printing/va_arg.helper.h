/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 06:04:11 by dthan             #+#    #+#             */
/*   Updated: 2025/06/01 07:49:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VA_ARG_HELPER_H
# define VA_ARG_HELPER_H
# include <stdarg.h>
# include "length.enum.h"

long long	        get_signed_nbr(t_length length, va_list arg);
unsigned long long	get_unsigned_nbr(t_length length, va_list arg);

#endif