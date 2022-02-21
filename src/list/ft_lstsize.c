/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 14:40:05 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 18:12:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*current;

	if (lst == NULL)
		return (0);
	count = 1;
	current = lst;
	while (current->next != NULL)
	{
		count++;
		current = (t_list *)current->next;
	}
	return (count);
}
