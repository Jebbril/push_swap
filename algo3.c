/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:12:40 by orakib            #+#    #+#             */
/*   Updated: 2023/01/20 17:35:42 by orakib           ###   ########.fr       */
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
			tmp->bestb = count - tmp->index;
		tmp = tmp->next;
	}
}

void	bestmovea(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmpa;
	int		middle;

	middle = (ft_lastnode(stack_a)->index + 1) / 2;
	tmp = *stack_b;
	tmpa = *stack_a;
	while (tmp)
	{
		if (tmp->value < (*stack_a)->value)
			tmp->besta = 0;
		else if (tmp->value > ft_lastnode(stack_a)->value)
			tmp->besta = 1;
		else
		{
			while (tmp->value > tmpa->value)
				tmpa = tmpa->next;
			if (tmpa->index <= middle)
				tmp->besta = tmpa->index;
			else
				tmp->besta = (ft_lastnode(stack_a)->index + 1) - tmpa->index;
		}
		tmpa = *stack_a;
		tmp = tmp->next;
	}
}
