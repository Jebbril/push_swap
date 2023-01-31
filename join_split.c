/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:49:59 by orakib            #+#    #+#             */
/*   Updated: 2023/01/31 15:34:21 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_joinsplit(int ac, char **av)
{
	char	**str;
	char	*joined;
	int		i;

	i = 0;
	while (i < (ac - 1))
	{
		if (!av[i + 1][0])
			return (NULL);
		joined = ft_strjoin(joined, av[i + 1]);
		joined = ft_strjoin(joined, " ");
		i++;
	}
	str = ft_split(joined, ' ');
	free(joined);
	return (str);
}

int	ft_countelm(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
