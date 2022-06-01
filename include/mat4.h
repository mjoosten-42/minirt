/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 13:24:03 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/01 13:43:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

# include "vec3.h"

typedef struct s_mat4
{
	double	data[4][4];
}	t_mat4;

t_mat4	matrix(t_v3 right, t_v3 up, t_v3 forward, t_v3 origin);

#endif