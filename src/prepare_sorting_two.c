/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sorting_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:29:38 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/11 17:38:40 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	q_sort(t_node **a_stack, t_node **b_stack);

void	sort_five_require(t_node **a_stack, t_node **b_stack, int which)
{
	t_node	*check;
	int		i;

	if (which)
	{
		i = find_node(a_stack, 1);
		while ((*a_stack)->pos != 1)
			take_movement(a_stack, i, 1);
		return ;
	}
	i = 6;
	check = *a_stack;
	while (--i)
	{
		if (check->pos != i)
		{
			push_pop(a_stack, b_stack, 1);
			push_pop(a_stack, b_stack, 1);
			sort_three(a_stack);
			break ;
		}
		check = check->next;
	}
	if (i == 0)
		q_sort(a_stack, b_stack);
}

void	sort_five(t_node **a_stack, t_node **b_stack)
{
	sort_five_require(a_stack, b_stack, 0);
	while (*b_stack != NULL)
	{
		if (!(*b_stack))
			break ;
		find_the_best(a_stack, b_stack);
		if ((*b_stack)->pos > check_max1(*a_stack)->pos && *b_stack)
		{
			while (check_max1(*a_stack)->pos != (*a_stack)->pos)
				ft_rx(a_stack, 1);
			ft_rx(a_stack, 1);
			push_pop(b_stack, a_stack, 0);
		}
		else if ((*b_stack)->pos < (*a_stack)->pos && *b_stack)
			push_pop(b_stack, a_stack, 0);
		else if ((*b_stack)->pos < check_min(*a_stack)->pos && *b_stack)
		{
			while (check_min(*a_stack)->pos == (*a_stack)->pos)
				sort_five_require(a_stack, NULL, 1);
			push_pop(b_stack, a_stack, 0);
		}
		else
			ft_rx(a_stack, 1);
	}
	sort_five_require(a_stack, NULL, 1);
}
