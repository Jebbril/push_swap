/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:19:11 by orakib            #+#    #+#             */
/*   Updated: 2023/01/27 17:43:42 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lis
{
	int	*lissize;
	int	*previndex;
	int	*seq;
}	t_lis;

typedef struct s_node
{
	int				value;
	int				index;
	int				lis;
	int				besta;
	int				bestb;
	int				bestmove;
	struct s_node	*next;

}	t_node;

t_node	*ft_newnode(int value);
t_node	*ft_lastnode(t_node **head);
void	ft_addback(t_node **head, t_node *node);
int		ft_atoi(const char *str);
void	ft_addtoa(int *arr, t_lis lis, t_node **stack_a, int co);
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
void	sort5(t_node **stack_a, t_node **stack_b);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	**ft_joinsplit(int ac, char **av);
int		ft_countelm(char **str);
t_lis	ft_getlis(int count);
void	ft_filllis(int *arr, t_lis lis, int count);
t_lis	ft_lis(int *arr, int count);
void	index_stack(t_node **stack);
void	push_unmarked(t_node **stack_a, t_node **stack_b);
void	bestmoveb(t_node **stack_b);
void	bestmovea(t_node **stack_a, t_node **stack_b);
void	baplusbb(t_node **stack_b);
t_node	*findbest(t_node **stack_b);
t_node	*get_next(t_node **stack, t_node *node);
t_node	*get_max(t_node **stack);
t_node	*get_min(t_node **stack);
void	push_all(t_node **stack_a, t_node **stack_b);
void	push_best(t_node **stack_a, t_node **stack_b);

#endif