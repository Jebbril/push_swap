/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:19:11 by orakib            #+#    #+#             */
/*   Updated: 2023/01/04 16:18:53 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;

}	t_node;

t_node	*ft_newnode(int value);
void	ft_addback(t_node **head, t_node *node);
int		ft_atoi(const char *str);
void	ft_addtoa(int *arr, t_node **stack_a, int ac);

#endif