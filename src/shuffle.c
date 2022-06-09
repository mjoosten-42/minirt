/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:06:14 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/09 15:33:24 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	*shuffle(int pixels)
{
	int	*shuffled;
	int	tmp;
	int	i;
	int	j;

	i = 0;
	shuffled = ft_malloc(sizeof(int) * pixels);
	while (i < pixels)
	{
		shuffled[i] = i;
		i++;
	}
	while (i-- > 1)
	{
		j = rand() % i;
		tmp = shuffled[j];
		shuffled[j] = shuffled[i];
		shuffled[i] = tmp;
	}
	return (shuffled);
}
