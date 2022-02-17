/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 10:32:26 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/17 11:13:41 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define COLOR_DEBUG_HEX_PRINT_MSG "COLORX: #%.8X\n"
# define COLOR_DEBUG_FLOAT_PRINT_MSG "COLORF: (%.3f, %.3f, %.3f)\n"

// # define C_BLACK 0xff000000
// # define C(r, g, b) (t_color){r, g, b}

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}			t_color;

static const t_color	g_black = (t_color){0, 0, 0};
static const t_color	g_white = (t_color){1, 1, 1};
static const t_color	g_red = (t_color){1, 0, 0};
static const t_color	g_green = (t_color){0, 1, 0};
static const t_color	g_blue = (t_color){0, 0, 1};

/* color_basics.c */
t_color	color_rgb(int r, int g, int b);
t_color	color_f(float r, float g, float b);
int		color_to_int(t_color c);
t_color	color_from_int(int c);
void	color_normalize(t_color *c);

/* color_math.c */
t_color	color_blend(t_color c1, t_color c2, float percentage);
void	color_luminosity(t_color *c, float multiplier);
void	color_norm_if_large(t_color *c);
void	color_cap(t_color *c);

/* color_debug.c */
void	color_print_hex(t_color c);
void	color_print_f(t_color c);

#endif
