/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percision.dto.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:26:44 by dthan             #+#    #+#             */
/*   Updated: 2025/05/24 11:28:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERCISION_DTO_H
# define PERCISION_DTO_H

struct  s_precision_dto
{
        int	specified;
        int	value;
};

typedef struct s_precision_dto	t_precision_dto;

#endif