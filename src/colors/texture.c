/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 16:06:07 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 17:16:36 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

mlx_texture_t	*load_texture(const char *fname)
{
	mlx_texture_t	*tex;
	
	tex = mlx_load_png(fname);
	if (tex == NULL)
		printf("Bad texture.\n");
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

	ipix = (int*)tex->pixels;
	y *= tex->height;
	x *= tex->width;
	color = ipix[tex->width * (int)y + (int)x];
	return (_color_from_int(color));
}
