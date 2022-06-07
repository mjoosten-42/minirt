/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:59:09 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/07 13:34:30 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include <fcntl.h>
#include "log.h"
#include "shape.h"
#include "shape_masks.h"
#include "libft.h"
#include "parse.h"
#include "light.h"

char		**get_args(char *line);
void		build_object(t_program *program, char **args);
t_object	get_object(t_program *program, char *str);
int			open_rt(char *file);

void	build_scene(t_program *program, char *file)
{
	char	**args;
	char	*line;
	int		fd;

	fd = open_rt(file);
	line = ft_get_next_line(fd);
	while (line)
	{
		args = get_args(line);
		if (args[0])
			build_object(program, args);
		free(line);
		ft_free_array(args);
		line = ft_get_next_line(fd);
	}
	close(fd);
	LOG("build scene");
	ft_lstiter(program->lights, (void (*)(void *))light_print);
	ft_lstiter(program->shapes, (void (*)(void *))shape_print);
	if (program->camera.fov == 0)
	{
		LOG_ERR("Missing camera");
		exit(EXIT_FAILURE);
	}
	if (program->lights == NULL && program->ambience.intensity == 0)
	{
		LOG_ERR("Missing lighting");
		exit(EXIT_FAILURE);
	}
	program->lights_amount = ft_lstsize(program->lights);
}

char	**get_args(char *line)
{
	char	**args;
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = 0;
	if (line[0] == ' ')
	{
		LOG_ERR("Line starting with space");
		exit(EXIT_FAILURE);
	}
	args = ft_split(line, ' ');
	if (!args)
	{
		LOG_ERR("split allocation failed");
		exit(EXIT_FAILURE);
	}
	return (args);
}

void	build_object(t_program *program, char **args)
{
	t_object	object;
	int			argsize;

	object = get_object(program, args[0]);
	argsize = ft_argsize(args);
	if (argsize != object.nb_args)
	{
		LOG_ERR("Wrong amount of arguments");
		exit(EXIT_FAILURE);
	}
	object.f(args, object.ptr);
}

t_object	get_object(t_program *program, char *str)
{
	const t_object	table[] = {
	{OBJECT_AMBIENCE, "A", 3, build_ambience, &program->ambience},
	{OBJECT_CAMERA, "C", 4, build_camera, &program->camera},
	{OBJECT_LIGHT, "L", 4, build_light, &program->lights},
	{OBJECT_SPHERE, "sp", 4, build_sphere, &program->shapes},
	{OBJECT_PLANE, "pl", 4, build_plane, &program->shapes},
	{OBJECT_CYLINDER, "cy", 6, build_cylinder, &program->shapes},
	{OBJECT_CIRCLE, "ci", 5, build_circle, &program->shapes}
	};
	int				tablesize;
	int				i;

	i = 0;
	tablesize = sizeof(table) / sizeof(*table);
	while (i < tablesize)
	{
		if (ft_strncmp(str, table[i].id, ft_strlen(str)) == 0)
			return ((t_object){table[i].type, table[i].id, table[i].nb_args, table[i].f, table[i].ptr});
		i++;
	}
	LOG_ERR(ft_strjoin(str, ": not an identifier"));
	exit(EXIT_FAILURE);
}

int	open_rt(char *file)
{
	int	fd;
	int	len;

	len = ft_strlen(file);
	if (len < 3 || ft_strncmp(file + len - 3, ".rt", len))
	{
		LOG_ERR("Expected .rt file");
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	LOG("Opened file");
	return (fd);
}
