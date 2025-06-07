/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.dto.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:55:49 by dthan             #+#    #+#             */
/*   Updated: 2025/05/24 11:01:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DTO_H
# define PRINT_DTO_H

struct s_print_dto
{
	char	*str;
	int	len;
};

typedef struct s_print_dto	t_print_dto;

t_print_dto *new_print_dto();

#endif