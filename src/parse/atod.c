/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:35:50 by mjoosten          #+#    #+#             */
/*   Updated: 2022/07/05 15:08:39 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "program.h"

double	atod(char *str)
{
	double	int_part;
	double	double_part;
	int		sign;
	int		len;
	int		i;

	i = 0;
	sign = 1;
	int_part = 0;
	double_part = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (!ft_isdigit(str[i]))
			rt_error(str, "double incorrectly formatted");
	}
	while (ft_isdigit(str[i]))
		int_part = 10 * int_part + (str[i++] - '0');
	if (!str[i])
		return (int_part * sign);
	if (str[i] != '.')
		rt_error(str, "double incorrectly formatted");
	i++;
	if (!ft_isdigit(str[i]))
		rt_error(str, "double incorrectly formatted");
	len = ft_strlen(str);
	while (len-- > i)
	{
		if (!ft_isdigit(str[len]))
			rt_error(str, "double incorrectly formatted");
		double_part = double_part / 10.0 + (double)(str[len] - '0') / 10.0;
	}
	return ((int_part + double_part) * sign);
}
