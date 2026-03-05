/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:02:26 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/30 15:13:53 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "../mylibft/includes/libft.h"

//	FOR TESTING
# include <stdio.h>

//	STRUCTURES
typedef struct s_stack
{
	int				value;
	int				index;
	int				price;
	int				distance;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//	FUNCTIONS
int			return_error(void);
int			argvlen(char **argv);
int			ft_lstlen(t_stack *lst);
int			ft_biggest(int x, int y);
void		*append_node(int n, t_stack **a);
void		*ft_isnumeric(char *str);
void		*check_double(long *tab);
void		*push_swap(t_stack **a, t_stack **b);
void		*free_stack(t_stack **a, t_stack **b);
void		*free_argv(char **argv, int len, int argc);
void		ft_cost(t_stack *a);
void		sort_three(t_stack **a);
void		ft_actualize(t_stack **a, t_stack **b);
void		ft_index_median_distance(t_stack *lst);
void		ft_cost_not_same_side(t_stack *current_a);
void		node_a_to_top(t_stack **a, t_stack *node);
void		node_b_to_top(t_stack **b, t_stack *node);
void		find_bigger_target(t_stack *a, t_stack *b);
void		find_smaller_target(t_stack *a, t_stack *b);
void		nodes_ab_to_top(t_stack **a, t_stack **b, \
			t_stack *node_a, t_stack *node_b);
void		nodes_ab_to_top2(t_stack **a, t_stack **b, \
			t_stack *node_a, t_stack *target);
bool		is_sorted(t_stack *stack);
long int	ft_atol(char *nbr);
long int	*ft_parsing(int argc, char **argv);
long int	*create_tab(int argc, char **argv);
t_stack		*init_stack_a(long *tab);
t_stack		*ft_lastnode(t_stack *lst);
t_stack		*find_cheapest(t_stack *a);
t_stack		*find_highest(t_stack *lst);
t_stack		*find_smallest(t_stack *lst);

//	MOVES
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rrb(t_stack **b);
void		rra(t_stack **a);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		swap(t_stack **a);
void		rotate(t_stack **a);
void		revrotate(t_stack **a);
void		push(t_stack **dst, t_stack **src);

#endif