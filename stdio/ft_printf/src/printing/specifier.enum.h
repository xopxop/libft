/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.enum.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:57:59 by dthan             #+#    #+#             */
/*   Updated: 2025/05/24 10:58:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_ENUM_H
# define SPECIFIER_ENUM_H

enum	e_specifier
{
	spec_char,
	spec_str,
	spec_ptr,
	spec_int,
	spec_uint,
	spec_octal,
	spec_hexlowcase,
	spec_hexupcase,
	spec_float,
	spec_percentsign,
	spec_none,
};

typedef enum e_specifier	t_specifier;

#endif