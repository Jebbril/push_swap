/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:12:02 by orakib            #+#    #+#             */
/*   Updated: 2023/01/13 17:20:20 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lis	ft_getlis(int *arr, int count)
{
	t_lis	lis;
	int		i;

	i = 0;
	lis.lissize = malloc(count * sizeof(int));
	lis.previndex = malloc(count * sizeof(int));
	while (i < count)
	{
		lis.lissize[i] = 1;
		lis.previndex[i] = -1;
		i++;
	}
	return (lis);
}
void	ft_filllis(int *arr, t_lis lis, int count)
{
	int	i;
	int	j;

	i = 1;
	while(i < count)
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

t_lis	ft_lis(int *arr, int count)
{
	t_lis	lis;

	lis = ft_getlis(arr, count);
	ft_filllis(arr, lis, count);
	return (lis);
}

// int	main(void)
// {
// 	int i = 0;
// 	t_lis	lis;
// 	int	arr[] = {-9 ,13, 94, -21, -99, -23, -84, 95, 49, -18, 11, 18, -59, 29, -39, -26, 83, -98, 46, 96, -10, 79, -94, -74, 66, -73, 39, -82, 87, -24, -55, -25, 78, -16, 24, -44, 3, -85, 74, 43, -97, 64, -62, -89, 55, -42, 61, -4, 40, -46, 52, 6, -58, 9, 44, 45, -19, 98, -1, 32, -79, 17, 30, 71, 82, 31, 53, -37, 8, 0, -13, -70, -63, -57, -92, -8, -77, -83, -5, 5, -30, -35, 59, -47, 51, -29, 2, -49, -90, 100, -96, -100, 20, 56, -87, -80, 10, -11, -43, -27};
// 	lis = ft_lis(arr, 100);
// 	while (i < 100)
// 	{
// 		printf("index : %d\t number : %d\t lis : %d\tprevindex : %d\n", i, arr[i], lis.lissize[i], lis.previndex[i]);
// 		i++;
// 	}
// }