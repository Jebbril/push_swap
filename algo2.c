/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:12:02 by orakib            #+#    #+#             */
/*   Updated: 2023/01/28 19:28:45 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lis	ft_getlis(int count)
{
	t_lis	lis;
	int		i;

	i = 0;
	lis.lissize = malloc(count * sizeof(int));
	lis.previndex = malloc(count * sizeof(int));
	lis.seq = malloc(count * sizeof(int));
	while (i < count)
	{
		lis.lissize[i] = 1;
		lis.previndex[i] = -1;
		lis.seq[i] = 0;
		i++;
	}
	return (lis);
}

void	ft_filllis(int *arr, t_lis lis, int count)
{
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j])
			{
				if (lis.lissize[i] < lis.lissize[j] + 1)
				{
					lis.lissize[i] = 1 + lis.lissize[j];
					lis.previndex[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_markseq(t_lis lis, int count)
{
	int	max;
	int	i;
	int	start;

	max = 0;
	i = 0;
	start = 0;
	while (i < count)
	{
		if (lis.lissize[i] > max)
		{
			max = lis.lissize[i];
			start = i;
		}
		i++;
	}
	i = 0;
	while (i < max)
	{
		lis.seq[start] = 1;
		start = lis.previndex[start];
		i++;
	}
}

t_lis	ft_lis(int *arr, int count)
{
	t_lis	lis;

	lis = ft_getlis(count);
	ft_filllis(arr, lis, count);
	ft_markseq(lis, count);
	return (lis);
}
