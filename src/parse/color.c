/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:23:19 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/23 16:02:20 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parse.h"
#include "libft.h"
#include "program.h"

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
			rt_error(str, "overflow");
		prev = result;
	}
	if (str[i] != 0 || result > 255)
		rt_error(str, "color incorrectly formatted");
	return ((float)result / 255.0f);
}

t_color	parse_color(char *str)
{
	t_color	color;
	char	**strs;

	strs = ft_split(str, ',');
	if (!strs)
		rt_error(NULL, "Split allocation failed");
	if (ft_argsize(strs) != 3)
		rt_error(str, "color incorrectly formatted");
	color.r = parse_rgb_value(strs[0]);
	color.g = parse_rgb_value(strs[1]);
	color.b = parse_rgb_value(strs[2]);
	ft_free_array(strs);
	return (color);
}
