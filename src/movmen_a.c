/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movmen_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:54:01 by nqasem            #+#    #+#             */
/*   Updated: 2024/12/25 19:03:55 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertend(t_node **root, long new_value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		exit(99);
		return ;
	}
	new_node->x = new_value;
	new_node->next = NULL;
	if (*root == NULL)
	{
		(*root) = new_node;
		return ;
	}
	curr = *root;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void	ft_ra(t_node **a_list)
{
	t_node	*curr;
	t_node	*cur2;

	curr = *a_list;
	while (curr->next)
	{
		if (curr->next->next)
			cur2 = curr->next;
		curr = curr->next;
	}
	curr->next = (*a_list);
	cur2->next = NULL;
	(*a_list) = curr;
}

void	ft_rra(t_node **a_list)
{
	t_node	*curr;

	curr = *a_list;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = (*a_list);
	curr = (*a_list)->next;
	(*a_list)->next = NULL;
	*a_list = curr;
}

void	ft_sa(t_node **a_list)
{
	t_node	*curr;

	curr = (*a_list)->next;
	(*a_list)->next = (*a_list)->next->next;
	curr->next = (*a_list);
	*a_list = curr;
	//write()
}
/*
void	ft_rrr(t_node **a_list, t_node **b_list)
{
	ft_rra(a_list);
	// ft_rrb(b_list);
	//write()
}*/
