/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:54:57 by orakib            #+#    #+#             */
/*   Updated: 2023/02/01 14:55:26 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_arr	ar;
	t_node	**stack_a;
	t_node	**stack_b;
	t_lis	lis;

	ar.i = 0;
	ar.count = 0;
	if (ac <= 1)
		return (0);
	ar.arr = ft_getnumbers(ac, av, &ar.count);
	if (!ar.arr || ft_checkrepeat(ar.arr, ar.count) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = malloc(sizeof(t_node));
	stack_b = malloc(sizeof(t_node));
	if (!stack_a || !stack_b)
		exit(1);
	lis = ft_lis(ar.arr, ar.count);
	*stack_b = NULL;
	ft_addtoa(ar.arr, lis, stack_a, ar.count);
	ft_sort(stack_a, stack_b);
	free_all(stack_a, stack_b, lis, ar.arr);
	return (0);
}
