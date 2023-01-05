/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:29:54 by orakib            #+#    #+#             */
/*   Updated: 2023/01/05 18:09:09 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*current;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	current = *stack_a;
	*stack_a = (*stack_a)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	ft_rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*current;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	current = *stack_b;
	*stack_b = (*stack_b)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rra(t_node **stack_a)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*current;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp1 = *stack_a;
	current = *stack_a;
	while (current->next->next != NULL)
		current = current->next;
	tmp2 = current->next;
	*stack_a = tmp2;
	tmp2->next = tmp1;
	current->next = NULL;
}

void	ft_rrb(t_node **stack_b)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*current;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp1 = *stack_b;
	current = *stack_b;
	while (current->next->next != NULL)
		current = current->next;
	tmp2 = current->next;
	*stack_b = tmp2;
	tmp2->next = tmp1;
	current->next = NULL;
}
