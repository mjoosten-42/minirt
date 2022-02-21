/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstremone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:19:27 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 18:12:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
**	difference between lstdelone and lstremone is that lstremone will
**	actually stitch the list back together if its an element from the
**	center
*/

void	ft_lstremone(t_list **head, t_list *element)
{
	t_list	*current;

	if (element == NULL)
		return ;
	if (*head == element)
	{
		*head = element->next;
		if (element->content != NULL)
			free(element->content);
		free(element);
		return ;
	}
	current = *head;
	while (current != NULL)
	{
		if (current->next == element)
		{
			current->next = element->next;
			if (element->content != NULL)
				free(element->content);
			free(element);
			return ;
		}
		current = current->next;
	}
}
