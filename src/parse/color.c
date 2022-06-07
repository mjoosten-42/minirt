/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:23:19 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/07 13:35:06 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parse.h"
#include "libft.h"
#include "log.h"

float	parse_rgb_value(char *str);

t_color	parse_color(char *str)
{
	t_color	color;
	char	**strs;

	strs = ft_split(str, ',');
	if (!strs)
	{
		LOG_ERR("Split allocation failed");
		exit(EXIT_FAILURE);
	}
	if (ft_argsize(strs) != 3)
	{
		LOG_ERR("Incorrect amount of RGB");
		exit(EXIT_FAILURE);
	}
	color.r = parse_rgb_value(strs[0]);
	color.g = parse_rgb_value(strs[1]);
	color.b = parse_rgb_value(strs[2]);
	ft_free_array(strs);
	return (color);
}

float	parse_rgb_value(char *str)
{
	int	result;
	int	prev;
	int	i;

	i = 0;
	prev = 0;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = 10 * result + (str[i++] - '0');
		if (prev > result)
		{
			LOG_ERR("Overflow");
			exit(EXIT_FAILURE);
		}
		prev = result;
	}
	if (str[i] != 0 || ft_strlen(str) > 3 || result > 255)
	{
		LOG_ERR("Incorrect RGB value");
		exit(EXIT_FAILURE);
	}
	return ((float)result / 255.0f);
}
