/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:59:09 by mjoosten          #+#    #+#             */
/*   Updated: 2022/05/27 13:59:10 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include <fcntl.h>
#include "log.h"
#include "shape.h"
#include "../lib/libft/include/libft.h"

t_shape	*get_shape(char **strs);
char	**get_param(char *line);
int		open_rt(char *file);
void	str_replace(char *str, char o, char r);

void	get_shapes(t_program *program, char *file)
{
	t_list	*new;
	t_shape	*shape;
	char	**strs;
	char	*line;
	int		fd;

	fd = open_rt(file);
	line = ft_get_next_line(fd);
	while (line)
	{
		str_replace(line, '\t', ' ');
		strs = ft_split(line, ' ');
		if (!strs)
		{
			LOG("ft_split allocation failed");
			exit(EXIT_FAILURE);
		}
		if (**strs != '\n')
		{
			shape = get_shape(strs);
			new = ft_lstnew(shape);
			ft_lstadd_front(&program->shapes, new);
		}
		ft_free_array(strs);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
}

t_shape	*get_shape(char **strs)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
	{
		LOG("Shape failed to allocate");
		exit(EXIT_FAILURE);
	}
	return (shape);
}

char	**get_param(char *line)
{
	char	**strs;

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
	if (len < 3)
	{
		LOG("Filename is too small");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(file + len - 3, ".rt", len))
	{
		LOG("File extension isn't .rt");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
