/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:56:31 by orakib            #+#    #+#             */
/*   Updated: 2023/02/01 14:55:19 by orakib           ###   ########.fr       */
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
