/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:04:41 by orakib            #+#    #+#             */
/*   Updated: 2023/01/22 17:06:24 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->besta = 0;
	new->bestb = 0;
	new->bestmove = 0;
	new->next = NULL;
	return (new);
}

void	ft_addback(t_node **head, t_node *node)
{
	t_node	*tmp;

	tmp = *head;
	if (tmp == NULL)
		tmp = node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->index = tmp->index + 1;
}

t_node	*ft_lastnode(t_node **head)
{
	t_node	*last;

	last = *head;
	while (last->next)
		last = last->next;
	return (last);
}
