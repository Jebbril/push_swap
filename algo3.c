/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:12:40 by orakib            #+#    #+#             */
/*   Updated: 2023/01/14 18:36:07 by orakib           ###   ########.fr       */
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

void	pushback(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	last;

	i = 0;
	last = ft_lastnode(stack_b)->index;
	while (i <= last)
	{
		if ((*stack_b)->value < (*stack_a)->value)
			pa(stack_a, stack_b);
		if ((*stack_b)->value > ft_lastnode(stack_a)->value)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		rb(stack_b);
		i++;
	}
}