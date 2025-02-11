/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:34:08 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/11 23:18:06 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_less_cost(t_node *lst)
{
	t_node	*best;
	t_node	*check;

	best = lst;
	check = lst;
	if (!lst)
		return (0);
	while (check)
	{
		if (check->cost < best->cost)
			best = check;
		check = check->next;
	}
	return (best);
}

void	calc_cost_a(t_node *a_stack, t_node *check_a, t_node *check_b, int i)
{
	int		size;

	size = lstsize(a_stack);
	while (check_a->pos < check_b->pos)
	{
		if (!(check_a->next))
		{
			check_a = a_stack;
			i = 0;
			if (check_a->pos <! check_b->pos)
				break ;
		}
		check_a = check_a->next;
		i++;
	}
	if ((size / 2) < i)
	{
		check_b->cost += ((size) - i);
		check_b->a_cost = (((size) - i)) * -1;
	}
	else
	{
		check_b->cost += i;
		check_b->a_cost = i;
	}
}

void	setup_calc_cost_a(t_node *a_stack, t_node *b_stack, t_node *minimum)
{
	t_node	*check_a;
	t_node	*check_b;
	int		i;

	check_b = b_stack;
	while (check_b)
	{
		i = 0;
		check_a = a_stack;
		while (check_a->pos != minimum->pos && check_a)
		{
			check_a = check_a->next;
			i++;
		}
		calc_cost_a(a_stack, check_a, check_b, i);
		check_b = check_b->next;
	}
}

t_node	*calc_cost_ab(t_node *b_stack, t_node *a_stack, t_node *minimum)
{
	t_node	*check_b;
	int		size;
	int		i;

	size = lstsize(b_stack);
	check_b = b_stack;
	i = 0;
	while (check_b != NULL)
	{
		if ((size / 2) <= i)
		{
			check_b->cost = ((size) - i) + 1;
			check_b->b_cost = (((size) - i) + 1) * -1;
		}
		else
		{
			check_b->cost = i;
			check_b->b_cost = i;
		}
		check_b = check_b->next;
		i++;
	}
	setup_calc_cost_a(a_stack, b_stack, minimum);
	return (find_less_cost(b_stack));
}

void	go_to_best_cost(t_node **stack_b, t_node **stack_a, t_node *best)
{
	int		i;

	i = find_node(stack_b, best->pos);
	while ((*stack_b)->pos != best->pos)
	{
		if (best->a_cost < 0 && best->b_cost < 0)
		{
			ft_rrr(stack_a, stack_b);
			best->a_cost ++;
			best->b_cost ++;
		}
		else if (best->a_cost > 0 && best->b_cost > 0)
		{
			ft_rr(stack_a, stack_b);
			best->a_cost --;
			best->b_cost --;
		}
		else
			take_movement(stack_b, i, 0);
	}
}
