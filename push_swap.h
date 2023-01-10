/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:19:11 by orakib            #+#    #+#             */
/*   Updated: 2023/01/10 15:59:01 by orakib           ###   ########.fr       */
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
	int				index;
	struct s_node	*next;

}	t_node;

t_node	*ft_newnode(int value);
void	ft_addback(t_node **head, t_node *node);
int		ft_atoi(const char *str);
void	ft_addtoa(int *arr, t_node **stack_a, int co);
void	ft_sa(t_node **stack_a);
void	ft_sb(t_node **stack_b);
void	ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);
void	ft_ra(t_node **stack_a);
void	ft_rb(t_node **stack_b);
void	ft_rr(t_node **stack_a, t_node **stack_b);
void	ft_rra(t_node **stack_a);
void	ft_rrb(t_node **stack_b);
void	ft_rrr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
int		ft_celt(t_node **stack_a);
void	ft_sort(t_node **stack_a, t_node **stack_b);
void	sort2(t_node **stack_a);
void	sort3(t_node **stack_a);
void	sort4(t_node **stack_a, t_node **stack_b);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	**ft_joinsplit(int ac, char **av);
int	ft_countelm(char **str);

#endif