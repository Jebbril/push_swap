/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:12:35 by orakib            #+#    #+#             */
/*   Updated: 2023/01/26 18:26:32 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_best(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*best;
	int		i;

	i = 0;
	tmp = *stack_b;
	best = *stack_b;
	while (tmp)
	{
		if (tmp->bestmove < best->bestmove)
			best = tmp;
		tmp = tmp->next;
	}
	
}

void	push_all(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b)
	{
	bestmoveb(stack_b);
	bestmovea(stack_a, stack_b);
	baplusbb(stack_b);
	
	}
}