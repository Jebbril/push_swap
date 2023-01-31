/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freenodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:12 by orakib            #+#    #+#             */
/*   Updated: 2023/01/31 15:31:25 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}

void	free_lis(t_lis lis)
{
	if (lis.lissize)
		free(lis.lissize);
	if (lis.previndex)
		free(lis.previndex);
	if (lis.lissize)
		free(lis.seq);
}

void	free_all(t_node **stack_a, t_node **stack_b, t_lis lis, int *arr)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_lis(lis);
	free(arr);
}
