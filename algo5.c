/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:12:35 by orakib            #+#    #+#             */
/*   Updated: 2023/01/27 18:11:17 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_best(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*best;
	int		i;

	tmp = *stack_b;
	best = *stack_b;
	while (tmp)
	{
		if (tmp->bestmove < best->bestmove)
			best = tmp;
		tmp = tmp->next;
	}
	i = 0;
	if (best->besta < 0)
	{
		while (i > best->besta)
		{
			rra(stack_a);
			i--;
		}
	}
	if (best->besta > 0)
	{
		while (i < best->besta)
		{
			ra(stack_a);
			i++;
		}
	}
	i = 0;
	if (best->bestb < 0)
	{
		while (i > best->bestb)
		{
			rrb(stack_b);
			i--;
		}
	}
	if (best->bestb > 0)
	{
		while (i < best->bestb)
		{
			rb(stack_b);
			i++;
		}
	}
	pa(stack_a, stack_b);
}

void	push_all(t_node **stack_a, t_node **stack_b)
{
	int	min;

	while (*stack_b)
	{
		bestmoveb(stack_b);
		bestmovea(stack_a, stack_b);
		baplusbb(stack_b);
		push_best(stack_a,stack_b);
		index_stack(stack_a);
		index_stack(stack_b);
	}
	min = get_min(stack_a)->value;
	while ((*stack_a)->value != min)
	{
		ra(stack_a);
	}
}