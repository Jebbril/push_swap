/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:08:34 by orakib            #+#    #+#             */
/*   Updated: 2023/01/05 18:39:42 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
}

void	ft_sb(t_node **stack_b)
{
	t_node	*tmp;

	if (tmp == NULL || tmp->next == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
}
