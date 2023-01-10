/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:06:54 by orakib            #+#    #+#             */
/*   Updated: 2023/01/09 15:03:12 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_countw(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == c)
			while (s[i] == c && i < len)
				i++;
		if (s[i] != c && i < len)
		{
			while (s[i] != c && i < len)
				i++;
			count++;
		}
	}
	return (count);
}

static char	**ft_alloc1(char const *s, char c, size_t *count)
{
	char	**str;

	*count = ft_countw(s, c);
	str = (char **)malloc((*count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[*count] = NULL;
	return (str);
}

static char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_alloc2(char const *s, char c, size_t *count)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	str = ft_alloc1(s, c, count);
	if (!str)
		return (NULL);
	while (s[i] && k < *count)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i++])
			j++;
		str[k] = (char *)malloc(sizeof(char) * (j + 1));
		if (!str[k++])
			return (ft_free(str));
		j = 0;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	str = ft_alloc2(s, c, &count);
	if (!str)
		return (NULL);
	while (j < count)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			str[j][k++] = s[i++];
		str[j][k] = 0;
		k = 0;
		j++;
	}
	return (str);
}
