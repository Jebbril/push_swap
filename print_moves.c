/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:40:28 by orakib            #+#    #+#             */
/*   Updated: 2023/01/07 13:44:13 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	ft_sa(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	ft_sb(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	ft_ss(stack_a, stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	ft_pa(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	ft_pb(stack_a, stack_b);
	write(1, "pb\n", 3);
}
