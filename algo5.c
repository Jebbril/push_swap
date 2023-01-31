/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:12:35 by orakib            #+#    #+#             */
/*   Updated: 2023/01/31 12:47:09 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rrr(t_node **stack_a, t_node **stack_b, t_node *best)
{
	while (best->besta > 0 && best->bestb > 0)
	{
		rr(stack_a, stack_b);
		best->besta--;
		best->bestb--;
	}
	while (best->besta < 0 && best->bestb < 0)
	{
		rrr(stack_a, stack_b);
		best->besta++;
		best->bestb++;
	}
}

void	rdy_stacks(t_node **stack_a, t_node **stack_b, t_node *best)
{
	int	i;

	i = 0;
	while (i > best->besta)
	{
		rra(stack_a);
		i--;
	}
	while (i < best->besta)
	{
		ra(stack_a);
		i++;
	}
	i = 0;
	while (i > best->bestb)
	{
		rrb(stack_b);
		i--;
	}
	while (i < best->bestb)
	{
		rb(stack_b);
		i++;
	}
}

void	push_best(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*best;

	tmp = *stack_b;
	best = *stack_b;
	while (tmp)
	{
		if (tmp->bestmove < best->bestmove)
			best = tmp;
		tmp = tmp->next;
	}
	rr_rrr(stack_a, stack_b, best);
	rdy_stacks(stack_a, stack_b, best);
	pa(stack_a, stack_b);
}

void	push_all(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;
	int		middle;

	while (*stack_b)
	{
		bestmoveb(stack_b);
		bestmovea(stack_a, stack_b);
		bestmove(stack_b);
		push_best(stack_a, stack_b);
		index_stack(stack_a);
		index_stack(stack_b);
	}
	min = get_min(stack_a);
	middle = (ft_lastnode(stack_a)->index + 1) / 2;
	while ((*stack_a)->value != min->value)
	{
		if (min->index < middle)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
