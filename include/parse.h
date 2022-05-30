/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:16:24 by mjoosten          #+#    #+#             */
/*   Updated: 2022/05/30 15:32:07 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include "shape.h"
#include "shape_masks.h"

typedef struct s_shape_table
{
	char			*id;
	void			*(*f)(char **);
	int				nb_args;
	t_shape_type	type;

}			t_shape_table;

void	*get_ambience(char **strs);
void	*get_camera(char **strs);
void	*get_light(char **strs);
void	*get_sphere(char **strs);
void	*get_plane(char **strs);
void	*get_cylinder(char **strs);

t_shape	*get_shape(char **strs);
int		ft_argsize(char **strs);

double	atod(char *str);

t_v3	parse_vector(char *str);
t_v3	parse_vector_norm(char *str);
t_color	parse_color(char *str);

#endif