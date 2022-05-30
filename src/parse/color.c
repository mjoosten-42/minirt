/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:23:19 by mjoosten          #+#    #+#             */
/*   Updated: 2022/05/30 14:46:30 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parse.h"
#include "../lib/libft/include/libft.h"
#include "log.h"

float	parse_rgb(char *str);

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
	color.r = parse_rgb(strs[0]);
	color.g = parse_rgb(strs[1]);
	color.b = parse_rgb(strs[2]);
	return (color);
}

float	parse_rgb(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (ft_isdigit(str[i]))
		result = 10 * result + (str[i++] - '0');
	if (str[i] != 0 || ft_strlen(str) > 3 || result > 255)
	{
		LOG_ERR("Incorrect RGB value");
		exit(EXIT_FAILURE);
	}
	return ((float)result / 255.0f);
}
