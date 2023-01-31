/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:22:48 by orakib            #+#    #+#             */
/*   Updated: 2023/01/31 12:46:18 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_celt(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->index + 1);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int	c;

	(void)stack_b;
	c = ft_celt(stack_a);
	if (c == 2)
		sort2(stack_a);
	else if (c == 3)
		sort3(stack_a);
	else if (c == 5)
		sort5(stack_a, stack_b);
	else
	{
		pushtob(stack_a, stack_b);
		push_all(stack_a, stack_b);
	}
}

void	sort2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort3(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack_a;
	second = first->next;
	third = second->next;
	if (first->value < second->value && second->value < third->value)
		return ;
	if (third->value > first->value)
	{
		sa(stack_a);
		if (first->value < second->value)
			ra(stack_a);
		return ;
	}
	if (second->value < first->value && second->value > third->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (second->value < first->value && second->value < third->value)
		ra(stack_a);
	else
		rra(stack_a);
}

void	sort5(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (tmp->value < tmp->next->value
		&& tmp->next->value < tmp->next->next->value
		&& tmp->next->next->value < tmp->next->next->next->value
		&& tmp->next->next->next->value < tmp->next->next->next->next->value)
		return ;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort3(stack_a);
	index_stack(stack_a);
	index_stack(stack_b);
	push_all(stack_a, stack_b);
}
