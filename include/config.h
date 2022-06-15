/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:53:24 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/15 15:59:29 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "material.h"
# include <math.h>

/* program.init.c */
# define WINDOW_W 1024
# define WINDOW_H 720
# define WINDOW_TITLE "minirt"
# define WINDOW_RESIZE 0

/* threads.c */
# define NB_THREADS 7

/* raycasting.c */
# define RAY_MAX_BOUNCES 16

/* anti_aliasing.c */
# define AA 1

/* shape.c */
# define DEFAULT_MATERIAL MATERIAL_DEFAULT
# define DEFAULT_REFLECTIVENESS 0.1
# define DEFAULT_PHONG INFINITY

#endif
