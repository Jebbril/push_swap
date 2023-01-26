/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:12:40 by orakib            #+#    #+#             */
/*   Updated: 2023/01/26 13:50:29 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_node **stack)
{
	t_node	*tmp;
	int		index;

	index = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}

void	push_unmarked(t_node **stack_a, t_node **stack_b)
{
	int	last;
	int	i;

	last = ft_lastnode(stack_a)->index;
	while (i <= last)
	{
		if ((*stack_a)->lis == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	index_stack(stack_a);
	index_stack(stack_b);
}

void	bestmoveb(t_node **stack_b)
{
	t_node	*tmp;
	int		middle;
	int		count;

	count = ft_lastnode(stack_b)->index + 1;
	middle = count / 2;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index <= middle)
			tmp->bestb = tmp->index;
		else
			tmp->bestb = (count - tmp->index) * -1;
		tmp = tmp->next;
	}
}

t_node	*get_max(t_node **stack)
{
	t_node	*tmp;
	t_node	*max;

	tmp = *stack;
	max = *stack;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_node	*get_min(t_node **stack)
{
	t_node	*tmp;
	t_node	*min;

	tmp = *stack;
	min = *stack;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*get_next(t_node **stack, t_node *node)
{
	t_node	*next;
	t_node	*tmp;

	tmp = *stack;
	next = get_max(stack);
	if(node->value > next->value)
		return (get_min(stack));
	while (tmp)
	{
		if (tmp->value > node->value && tmp->value < next->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

void	bestmovea(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmpa;
	int		middle;
	int		count;

	count = ft_lastnode(stack_a)->index + 1;
	middle = count / 2;
	tmp = *stack_b;
	tmpa = *stack_a;
	while (tmp)
	{
		tmp->besta = get_next(stack_a, tmp)->index;
		if (tmp->besta > middle)
			tmp->besta = (count - tmp->besta) * -1;
		tmp = tmp->next;
	}
}
