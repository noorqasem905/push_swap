/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:32 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/12 00:08:34 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct node
{
	long		x;
	int			pos;
	int			cost;
	int			a_cost;
	int			b_cost;
	struct node	*next;
}				t_node;
int			find_node(t_node **lst, int pos);
int			check_sort(t_node **lst);
int			sort_rev(t_node **lst);
int			lstsize(t_node *lst);
t_node		*check_min(t_node *lst);
t_node		*check_max1(t_node *lst);
t_node		*calc_cost_ab(t_node *b_stack,
				t_node *a_stack, t_node *minimum);
t_node		*find_less_cost(t_node *lst);
t_node		*push_three(t_node **a_stack, t_node **b_stack);
t_node		*find_the_best(t_node **a_stack, t_node **b_stack);
void		sort_three(t_node **lst);
void		set_postion(t_node *lst);
void		ft_sx(t_node **list, int which);
void		ft_rx(t_node **b_list, int which);
void		ft_rr(t_node **a_list, t_node **b_list);
void		ft_rrx(t_node **list, int which);
void		ft_rrr(t_node **a_list, t_node **b_list);
void		go_to_best_cost(t_node **stack_b, t_node **stack_a, t_node *best);
void		push_pop(t_node **src, t_node **dest, int print);
void		take_movement(t_node **lst, int cost, int which);
void		calc_cost_a(t_node *a_stack, t_node *check_a,
				t_node *check_b, int i);
long		h_ft_atoi(const char *str, int *flag);
void		setup_calc_cost_a(t_node *a_stack,
				t_node *b_stack, t_node *minimum);
void		set_values(int *i, int *neg, long *c, int *j);
void		push_to_its_section(t_node **a_stack,
				t_node **b_stack, t_node *best);
void		insertend(t_node **root, long new_value);
void		frees(t_node **root);
void		error_message(int flag);
void		h_in_pool(t_node **node, int *flag, char **argv);
void		h_repeat_num(t_node **node);

#endif
