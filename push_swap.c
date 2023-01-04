/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:56:31 by orakib            #+#    #+#             */
/*   Updated: 2023/01/04 18:09:41 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addtoa(int *arr, t_node **stack_a, int ac)
{
	int	i;
	t_node *tmp;

	i = 0;
	*stack_a = ft_newnode(arr[i++]);
	while (i < (ac - 1))
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

int	*ft_getnumbers(int ac, char **av)
{
	int	i;
	int	*arr;

	i = 0;
	if (ac > 1)
	{
		arr = malloc((ac - 1) * sizeof(int));
		while (i < (ac - 1))
		{
			if (ft_checknumber(av[i + 1]))
			{
				free(arr);
				return (NULL);
			}
			arr[i] = ft_atoi(av[i + 1]);
			i++;
		}
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
	t_node	*tmp;

	i = 0;
	arr = ft_getnumbers(ac, av);
	if (!arr)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = malloc(sizeof(t_node));
	stack_b = malloc(sizeof(t_node));
	ft_addtoa(arr, stack_a, ac);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
