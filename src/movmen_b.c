/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movmen_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:54:01 by nqasem            #+#    #+#             */
/*   Updated: 2024/12/25 19:04:28 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_node **b_list)
{
	t_node	*curr;
	t_node	*cur2;

	curr = *b_list;
	while (curr->next)
	{
		if (curr->next->next)
			cur2 = curr->next;
		curr = curr->next;
	}
	curr->next = (*b_list);
	cur2->next = NULL;
	(*b_list) = curr;
	//write()
}

void	ft_rrb(t_node **b_list)
{
	t_node	*curr;

	curr = *b_list;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = (*b_list);
	curr = (*b_list)->next;
	(*b_list)->next = NULL;
	*b_list = curr;
	//write()
}

void	ft_sb(t_node **b_list)
{
	t_node	*curr;

	curr = (*b_list)->next;
	(*b_list)->next = (*b_list)->next->next;
	curr->next = (*b_list);
	*b_list = curr;
	//write()
}
/*
void	ft_rr(t_node **a_list, t_node **b_list)
{
	// ft_ra(a_list);
	ft_rb(b_list);
	//write()
}*/
