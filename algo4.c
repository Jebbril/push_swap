/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:39:43 by orakib            #+#    #+#             */
/*   Updated: 2023/01/22 19:22:06 by orakib           ###   ########.fr       */
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
