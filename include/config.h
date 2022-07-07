/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 11:53:24 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/07 14:33:09 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/* debugging can be enabled by compiling with ENABLE_DEBUG */
# ifndef ENABLE_DEBUG
#  define ENABLE_DEBUG 0
# endif

/* program.init.c */
# define WINDOW_W 1024
# define WINDOW_H 720
# define WINDOW_TITLE "minirt"
# define WINDOW_RESIZE 0

/* threads.c */
# define NB_THREADS 8

/* raycasting.c */
# define RAY_MAX_BOUNCES 8

/* anti_aliasing.c */
# define AA 1

/* shape.c */
# define DEFAULT_PHONG 4

# define ENABLE_SPECULAR 1

/* plane.c */
# define PLANE_COORDINATE_DIVIDER 64.0

#endif
