/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:25:23 by dthan             #+#    #+#             */
/*   Updated: 2025/05/23 11:13:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../ft_printf.h"
#include "../utility/ft_utility.h"
#include "../string/ft_string.h"

float	ft_pow(float x, int y)
{
	float	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}

char	*ft_decimal(long double *nbr)
{
	char	*str;

	str = ft_itoa_unsigned_longlong((long long)*nbr);
	*nbr = *nbr - (long)*nbr;
	return (str);
}

char	*ft_fractional(long double nbr, t_info *info)
{
	char	*str;
	int		i;

	str = NULL;
	nbr *= 10;
	i = 1;
	if (info->percision > 0)
	{
		str = ft_strnew(info->percision + 1);
		str[0] = '.';
		while (info->percision-- > 0)
		{
			str[i++] = (int)nbr + '0';
			nbr = (nbr - (int)nbr) * 10;
		}
	}
	return (str);
}

void	float_to_string(long double num, t_info *info, char **str)
{
	char	*str_decimal;
	char	*str_fractional;
	int		negative;

	if (special_case(str, num))
		return ;
	negative = 0;
	if (num < 0)
	{
		negative = 1;
		num *= -1;
	}
	if (!negative || info->percision < 6)
		num += (0.5 * ft_pow(0.1, info->percision));
	else
		num += (0.1 * ft_pow(0.1, info->percision));
	str_decimal = ft_decimal(&num);
	str_fractional = ft_fractional(num, info);
	*str = ft_strjoin(str_decimal, str_fractional);
	if (negative)
		*str = ft_strjoin_and_free("-", *str, 0 ,1);
	free(str_decimal);
	free(str_fractional);
}

void	type_f(t_info *info, va_list arg, size_t *ct, int fd)
{
	long double	num;
	char		*str;
	int			negative;

	negative = 0;
	if (info->length == len_l)
		num = (long double)va_arg(arg, double);
	else if (info->length == len_lup)
		num = va_arg(arg, long double);
	else
		num = (long double)va_arg(arg, double);
	if (num < 0)
		negative = 1;
	if (info->percision == -1)
		info->percision = 6;
	float_to_string(num, info, &str);
	flag_ignore(info, str);
	flag_control(info, &str, negative);
	width_ctrl(info, &str);
	write(fd, str, *ct = ft_strlen(str));
	free(str);
}

#include "output.h"

t_output	*get_print_info_from_type_f(t_info *info, va_list arg)
{
	t_output	*output;
	long double	nbr;

	// need to handle length
	nbr = va_arg(arg, long double);
	output = new_output();
	output->len = get_output_len(info->field_width, info->percision);
	output->str = get_output_str();
	return (output);
}


char	*precision_control_float(long double nbr, t_precision precision)
{
	int precision_value;
	int is_negative_nbr;
	char *str;

	is_negative_nbr = is_negative(nbr);
	if (is_negative_nbr)
		nbr *= -1;
	if (is_negative_nbr)
		nbr += 0.5; // need to change
	else
		nbr += 0.1; // need to change
	str = ft_strjoin_and_free(decimal_value(nbr), fractional_value(nbr), 1, 1);
	if (is_negative_nbr)
		str = ft_strjoin_and_free("-", str, 0, 1);
	return (str);
}