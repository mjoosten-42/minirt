/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_debug.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 12:10:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/16 12:37:13 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>

void	color_print_hex(t_color c)
{
	printf(COLOR_DEBUG_HEX_PRINT_MSG, color_to_int(c));
}

void	color_print_f(t_color c)
{
	printf(COLOR_DEBUG_FLOAT_PRINT_MSG, c.r, c.g, c.b);
}
