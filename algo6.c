/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:36:16 by orakib            #+#    #+#             */
/*   Updated: 2023/01/29 19:16:35 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushonetob(t_node **stack_a, t_node **stack_b, t_node *tmp)
{
	int	i;
	int	middle;

	i = 0;
	middle = (ft_lastnode(stack_a)->index + 1) / 2;
	if (tmp->index < middle)
	{
		while (i < tmp->index)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		while (i + tmp->index < ft_lastnode(stack_a)->index + 1)
		{
			rra(stack_a);
			i++;
		}
	}
	pb(stack_a, stack_b);
}

void	pushtob(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	while(tmp)
	{
		if (tmp->lis == 0)
		{
			pushonetob(stack_a, stack_b, tmp);
			tmp = *stack_a;
			index_stack(stack_a);
		}
		else
			tmp = tmp->next;
	}
	index_stack(stack_b);
}