/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:16:24 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/15 11:16:50 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "shape.h"
# include "shape_masks.h"
# include "light.h"

typedef enum e_object
{
	OBJECT_NONE,
	OBJECT_CAMERA,
	OBJECT_LIGHT,
	OBJECT_AMBIENCE,
	OBJECT_PLANE,
	OBJECT_SPHERE,
	OBJECT_CYLINDER
}	t_object_type;

/**
**	@param type <t_object> Object enum
**	@param id <char*> Letter identifier
**	@param nb_args <int> Amount of arguments
**	@param f <void(*f)(char **, void *)> Function to return object
**	@param ptr <void*> Second argument of f: address to put object in/add to
*/
typedef struct s_object
{
	t_object_type	type;
	char			*id;
	int				nb_args;
	void			(*f)(char **, void *);
	void			*ptr;
}					t_object;

void	rt_error(char *s1, char *s2);

void	build_ambience(char **args, void *ptr);
void	build_camera(char **args, void *ptr);
void	build_light(char **args, void *ptr);

void	light_print(t_light *light);

double	atod(char *str);

t_v3	parse_vector(char *str);
t_v3	parse_vector_norm(char *str);
t_color	parse_color(char *str);

#endif