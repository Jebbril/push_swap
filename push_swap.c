/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:56:31 by orakib            #+#    #+#             */
/*   Updated: 2023/01/31 15:34:03 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addtoa(int *arr, t_lis lis, t_node **stack_a, int co)
{
	int		i;
	t_node	*tmp;

	i = 0;
	*stack_a = ft_newnode(arr[i++]);
	if (lis.seq[0] == 1)
		(*stack_a)->lis = 1;
	while (i < co)
	{
		tmp = ft_newnode(arr[i]);
		if (lis.seq[i] == 1)
			tmp->lis = 1;
		ft_addback(stack_a, tmp);
		i++;
	}
}

int	ft_checknumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkrepeat(int *arr, int co)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = 0;
	while (i < co)
	{
		j = 0;
		tmp = arr[i];
		count = 0;
		while (j < co)
		{
			if (tmp == arr[j])
				count++;
			j++;
		}
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	*ft_getnumbers(int ac, char **av, int *co)
{
	int		i;
	int		*arr;
	char	**str;

	i = -1;
	str = ft_joinsplit(ac, av);
	*co = ft_countelm(str);
	arr = malloc(*co * sizeof(int));
	if (!arr || !str)
		return (NULL);
	while (str[++i])
	{
		if (ft_checknumber(str[i]))
		{
			free(arr);
			return (NULL);
		}
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483647 -1)
			return (NULL);
		arr[i] = ft_atoi(str[i]);
		free(str[i]);
	}
	free(str);
	return (arr);
}

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
