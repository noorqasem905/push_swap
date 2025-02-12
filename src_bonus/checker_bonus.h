/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:32 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/12 18:22:25 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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
int			error_message(int flag);
int			check_sort(t_node **lst);
int			input(t_node **a_stack, t_node **b_stack);
int			lstsize(t_node *lst);
int			check_line(char *line, t_node **a_stack, t_node **b_stack);
void		set_postion(t_node *lst);
void		sx(t_node **list);
void		rx(t_node **b_list);
void		rr(t_node **a_list, t_node **b_list);
void		rrx(t_node **list);
void		rrr(t_node **a_list, t_node **b_list);
void		push(t_node **src, t_node **dest);
long		h_ft_atoi(const char *str, int *flag);
void		set_values(int *i, int *neg, long *c, int *j);
void		insertend(t_node **root, long new_value);
void		frees(t_node **root);
void		h_in_pool(t_node **node, int *flag, char **argv);
void		h_repeat_num(t_node **node);

#endif
