/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:39:43 by orakib            #+#    #+#             */
/*   Updated: 2023/01/26 14:13:06 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	baplusbb(t_node **stack_b)
{
	t_node	*tmp;
	int		absa;
	int		absb;

	tmp = *stack_b;
	while (tmp)
	{
		absa = tmp->besta;
		absb = tmp->bestb;
		if (absa < 0)
			absa = absa * -1;
		if (absb < 0)
			absb = absb * -1;
		tmp->bestmove = absa + absb;
		tmp = tmp->next;
	}
}

t_node	*findbest(t_node **stack_b)
{
	int		min;
	t_node	*tmp;
	t_node	*best;

	tmp = *stack_b;
	best = *stack_b;
	min = tmp->bestmove;
	while (tmp)
	{
		if (tmp->bestmove < min)
		{
			min = tmp->bestmove;
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
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
