/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:56:31 by orakib            #+#    #+#             */
/*   Updated: 2023/01/13 17:19:16 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addtoa(int *arr, t_node **stack_a, int co)
{
	int		i;
	t_node	*tmp;

	i = 0;
	*stack_a = ft_newnode(arr[i++]);
	while (i < co)
	{
		tmp = ft_newnode(arr[i]);
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

	i = 0;
	if (ac > 1)
	{
		str = ft_joinsplit(ac, av);
		*co = ft_countelm(str);
		arr = malloc(*co * sizeof(int));
		while (str[i])
		{
			if (ft_checknumber(str[i]))
			{
				free(arr);
				return (NULL);
			}
			arr[i] = ft_atoi(str[i]);
			free(str[i]);
			i++;
		}
		free(str);
		return (arr);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int		i;
	int		*arr;
	t_node	**stack_a;
	t_node	**stack_b;
	int		count;
	t_lis	lis;
	// t_node	*tmpa;
	// t_node	*tmpb;

	i = 0;
	count = 0;
	arr = ft_getnumbers(ac, av, &count);
	if (!arr || ft_checkrepeat(arr, count) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	lis = ft_lis(arr, count);
	while (i < count)
	{
		printf("index : %d\t number : %d\t lis : %d\tprevindex : %d\n", i, arr[i], lis.lissize[i], lis.previndex[i]);
		i++;
	}
	stack_a = malloc(sizeof(t_node));
	stack_b = malloc(sizeof(t_node));
	*stack_b = NULL;
	ft_addtoa(arr, stack_a, count);
	free(arr);
	ft_sort(stack_a, stack_b);
	// tmpa = *stack_a;
	// while (tmpa != NULL)
	// {
	// 	printf("%d\t%d\n", tmpa->index, tmpa->value);
	// 	tmpa = tmpa->next;
	// }
	// printf("\n");
	// tmpb = *stack_b;
	// while (tmpb != NULL)
	// {
	// 	printf("%d\t%d\n", tmpb->index, tmpb->value);
	// 	tmpb = tmpb->next;
	// }
	// system("leaks a.out");
	return (0);
}
