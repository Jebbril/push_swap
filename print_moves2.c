/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:40:31 by orakib            #+#    #+#             */
/*   Updated: 2023/01/07 13:50:35 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	ft_ra(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	ft_rb(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rr(stack_a, stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_node **stack_a)
{
	ft_rra(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	ft_rrb(stack_b);
	write(1, "rrb\n", 4);
}
