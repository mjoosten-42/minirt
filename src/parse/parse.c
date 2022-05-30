/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:59:09 by mjoosten          #+#    #+#             */
/*   Updated: 2022/05/30 15:47:40 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include <fcntl.h>
#include "log.h"
#include "shape.h"
#include "shape_masks.h"
#include "../lib/libft/include/libft.h"
#include "parse.h"

char	**get_next_parameters(int fd);
int		open_rt(char *file);

void	get_shapes(t_program *program, char *file)
{
	t_list	*new;
	t_shape	*shape;
	char	**strs;
	int		fd;

	fd = open_rt(file);
	strs = get_next_parameters(fd);
	while (strs)
	{
		shape = get_shape(strs);
		new = ft_lstnew(shape);
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(&program->shapes, new);
		LOG("Added shape");
		ft_free_array(strs);
		strs = get_next_parameters(fd);
	}
	LOG("Initialized shapes");
	close(fd);
	ft_lstiter(program->shapes, (void (*)(void *))shape_print);
}

t_shape	*get_shape(char **strs)
{
	const static t_shape_table	table[] = {
		{ "A", get_ambience, 3, SHAPE_NONE },
		{ "C", get_camera, 4, SHAPE_NONE },
		{ "L", get_light, 4, SHAPE_NONE },
		{ "sp", get_sphere, 4, SHAPE_SPHERE },
		{ "pl", get_plane, 4, SHAPE_PLANE },
		{ "cy", get_cylinder, 6, SHAPE_CYLINDER }
	};
	t_shape	*shape;
	int		tablesize;
	int		argsize;
	int		i;

	i = 0;
	tablesize = sizeof(table) / sizeof(*table);
	shape = ft_malloc(sizeof(t_shape));
	while (i < tablesize)
	{
		if (!ft_strncmp(*strs, table[i].id, ft_strlen(table[i].id)))
		{
			argsize = ft_argsize(strs);
			if (argsize != table[i].nb_args)
			{
				LOG_ERR("Wrong amount of arguments");
				exit(EXIT_FAILURE);
			}
			shape->type = table[i].type;
			if (**strs != 'A')
				shape->origin = parse_vector(strs[1]);
			shape->mask = table[i].f(strs);
			if (**strs != 'C')
				shape->color = parse_color(strs[argsize - 1]);
			return (shape);
		}
		i++;
	}
	LOG_ERR(ft_strjoin(*strs, ": not an identifier"));
	exit(EXIT_FAILURE);
}

char	**get_next_parameters(int fd)
{
	char	**strs;
	char	*line;
	size_t	len;

	line = ft_get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = 0;
	strs = ft_split(line, ' ');
	if (!strs)
	{
		LOG_ERR("ft_split allocation failed");
		exit(EXIT_FAILURE);
	}
	free(line);
	if (line[0] == ' ' && strs[0])
	{
		LOG_ERR("Line starting with space");
		exit(EXIT_FAILURE);
	}
	if (!strs[0])
		return (get_next_parameters(fd));
	return (strs);
}

int	open_rt(char *file)
{
	int	fd;
	int	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(file);
	if (len < 3 || ft_strncmp(file + len - 3, ".rt", len))
	{
		LOG_ERR("Expected .rt file");
		exit(EXIT_FAILURE);
	}
	LOG("Opened file");
	return (fd);
}

int	ft_argsize(char **strs)
{
	int	i = 0;
	while (strs[i])
		i++;
	return (i);
}
