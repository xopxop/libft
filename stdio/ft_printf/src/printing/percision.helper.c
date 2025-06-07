/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percision.helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:51:58 by dthan             #+#    #+#             */
/*   Updated: 2025/06/06 15:41:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "percision.dto.h"
#include "../string/ft_string.h"
#include "../utility/ft_utility.h"

char	*precision_string(t_precision_dto *precision, char *str)
{
	char	*new_str;	

	if (!precision->specified)
		return (str);
	if (precision->value > ft_strlen(str))
		return (str);
	new_str = ft_strnew(precision->value);
	ft_memcpy(new_str, str, precision->value);
	free(str);
	return (new_str);
}

char	*precision_integer(t_precision_dto precision, char *str, int negative_sign)
{
	char	*new_str;

	if (!precision.specified)
		return (str);
	if (precision.value == 0 && ft_strequ(str, "0"))
	{
		free(str);
		return (ft_strdup("0"));
	}
	if (precision.value + negative_sign <= ft_strlen(str))
		return (str);
	new_str = ft_strnew(precision.value);
	if (!new_str)
		return (NULL);
	if (negative_sign)
		new_str[0] = '-';
	ft_memset(new_str + negative_sign, '0', precision.value - ft_strlen(*str));
	ft_strcpy(new_str + precision.value - ft_strlen(*str) + negative_sign, *str);
	free(str);
	return (new_str);
}

char	*precision_float(t_precision_dto precision, long double nbr)
{
	char *decimal_value;
	char *fractional_value;

	if (nbr != nbr)
		return (ft_strdup("nan"));
	if (nbr == (10.0 / 0.0) || nbr == (-10.0 / 0.0))
		return (ft_strdup("inf"));
	decimal_value = get_decimal_value(nbr);
	fractional_value = get_fractional_value(nbr, precision);
	return (ft_strjoin_and_free(decimal_value, fractional_value, 1, 1));
}
