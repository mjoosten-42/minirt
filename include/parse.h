/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 13:16:24 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/05 16:42:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "shape.h"
# include "shape_masks.h"
# include "light.h"
# include "objects.h"
# include "program.h"

void	build_ambience(t_object object, char **args, t_program *program);
void	build_camera(t_object object, char **args, t_program *program);
void	build_light(t_object object, char **args, t_program *program);

char	*double_err_check(char *str);
double	atod(char *str);

t_v3	parse_vector(char *str);
t_v3	parse_vector_norm(char *str);
t_color	parse_color(char *str);

#endif