/* ************************************************************************** */
/*                                                                            */
<<<<<<< HEAD
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:53:24 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/17 17:09:43 by mjoosten         ###   ########.fr       */
=======
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 11:53:24 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/06/17 16:18:06 by ngerrets      ########   odam.nl         */
>>>>>>> 423b25f2f0b485ad344f53ff591747d2d35a8cd2
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
<<<<<<< HEAD
# define NB_THREADS 7
=======
# define NB_THREADS 8
>>>>>>> 423b25f2f0b485ad344f53ff591747d2d35a8cd2

/* raycasting.c */
# define RAY_MAX_BOUNCES 8

/* anti_aliasing.c */
# define AA 1

/* shape.c */
<<<<<<< HEAD
# define DEFAULT_PHONG 10

=======
# define DEFAULT_PHONG 4
>>>>>>> 423b25f2f0b485ad344f53ff591747d2d35a8cd2
#endif
