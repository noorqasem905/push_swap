/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:43:24 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/11 23:58:09 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_postion(t_node *lst)
{
	t_node		*nxt;
	t_node		*first;
	int			size;
	int			i;

	nxt = lst;
	first = lst;
	size = lstsize(lst);
	while (lst && size > 1)
	{
		i = 0;
		while (nxt)
		{
			if (lst->x > nxt->x)
				i++;
			nxt = nxt->next;
		}
		lst->pos = ((i) + 1);
		lst = lst->next;
		nxt = first;
	}
}

int	find_node(t_node **lst, int pos)
{
	t_node		*check;
	int			i;

	i = 0;
	check = *lst;
	while (check && (check)->pos != pos)
	{
		check = check->next;
		i++;
	}
	return (i);
}

void	take_movement(t_node **lst, int cost, int which)
{
	if (cost < lstsize(*lst) / 2)
		ft_rx(lst, which);
	else
		ft_rrx(lst, which);
}

t_node	*find_the_best(t_node **a_stack, t_node **b_stack)
{
	t_node		*best;
	t_node		*check;
	int			i;

	best = NULL;
	if ((*b_stack)->pos < (*a_stack)->pos)
	{
		i = lstsize(*a_stack);
		best = *a_stack;
		check = (*a_stack)->next;
		while (--i)
		{
			if ((check)->pos < best->pos && (*b_stack)->pos < check->pos)
				best = check;
			check = check->next;
		}
		i = find_node(a_stack, best->pos);
		while (best->pos != (*a_stack)->pos)
			take_movement(a_stack, i, 1);
	}
	return (best);
}

void	push_to_its_section(t_node **a_stack, t_node **b_stack, t_node *best)
{
	int	j;

	j = best->a_cost;
	if (j < 0)
		j *= -1;
	while (1)
	{
		while (j--)
		{
			if (best->a_cost < 0)
				ft_rrx(a_stack, 1);
			else
				ft_rx(a_stack, 1);
		}
		find_the_best(a_stack, b_stack);
		if ((*b_stack)->pos < (*a_stack)->pos)
		{
			push_pop(b_stack, a_stack, 0);
			break ;
		}
	}
}
