/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:35:50 by mjoosten          #+#    #+#             */
/*   Updated: 2022/05/30 12:55:16 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include "log.h"

double	atod(char *str)
{
	double	int_part;
	double	double_part;
	int		min;
	int		len;
	int		i;

	i = 0;
	min = 0;
	int_part = 0;
	double_part = 0;
	if (str[i] == '-')
	{
		min = 1;
		i++;
		if (!ft_isdigit(str[i]))
		{
			LOG_ERR(ft_strjoin(str, " : incorrectly formatted"));
			exit(EXIT_FAILURE);
		}
	}
	while (ft_isdigit(str[i]))
		int_part = 10 * int_part + (str[i++] - '0');
	if (!str[i])
		return (int_part);
	if (str[i] != '.')
	{
		LOG_ERR(ft_strjoin(str, " : incorrectly formatted"));
		exit(EXIT_FAILURE);
	}
	i++;
	if (!ft_isdigit(str[i]))
	{
		LOG_ERR(ft_strjoin(str, " : incorrectly formatted"));
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(str);
	while (len-- > i)
	{
		if (!ft_isdigit(str[len]))
		{
			LOG_ERR(ft_strjoin(str, " : incorrectly formatted"));
			exit(EXIT_FAILURE);
		}
		double_part = double_part / 10 + (double)(str[len] - '0') / 10;
	}
	if (min)
		return (-(int_part + double_part));
	return (int_part + double_part);
}
