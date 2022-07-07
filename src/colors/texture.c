/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:06:07 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 15:28:44 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "equations.h"

mlx_texture_t	*load_texture(const char *fname)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(fname);
	if (tex == NULL)
		rt_error(NULL, NULL);
	return (tex);
}

static t_color	_color_from_int(int c)
{
	unsigned char	trgb[4];
	t_color			result;

	*(int *)trgb = c;
	result.r = (float)trgb[0] / 255.0;
	result.g = (float)trgb[1] / 255.0;
	result.b = (float)trgb[2] / 255.0;
	return (result);
}

t_color	texture_get_color(mlx_texture_t *tex, double x, double y)
{
	int	color;
	int	*ipix;

	ipix = (int *)tex->pixels;
	y *= tex->height;
	x *= tex->width;
	x = clamp(x, 0.0, tex->width - 1.0);
	y = clamp(y, 0.0, tex->height - 1.0);
	color = ipix[tex->width * (int)y + (int)x];
	return (_color_from_int(color));
}
