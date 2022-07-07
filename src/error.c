/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:55:04 by mjoosten          #+#    #+#             */
/*   Updated: 2022/07/07 10:38:16 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rt_error(char *s1, char *s2)
{
	ft_putendl_fd("Error", 2);
	if (s1)
	{
		ft_putstr_fd(s1, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(s2, 2);
	exit(EXIT_FAILURE);
}
