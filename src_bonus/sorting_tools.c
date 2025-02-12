/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:54:01 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/12 17:46:44 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrx(t_node **list)
{
	t_node	*prev;
	t_node	*cur;

	if ((*list) == NULL)
		return ;
	if ((*list)->next == NULL)
		return ;
	prev = *list;
	cur = prev->next;
	while (cur->next)
	{
		prev = prev->next;
		if (prev->next)
			cur = prev->next;
	}
	cur->next = (*list);
	prev->next = NULL;
	(*list) = cur;
}

void	rx(t_node **b_list)
{
	t_node	*curr;

	if ((*b_list) == NULL)
		return ;
	if ((*b_list)->next == NULL)
		return ;
	curr = *b_list;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = (*b_list);
	curr = (*b_list)->next;
	(*b_list)->next = NULL;
	*b_list = curr;
}

void	sx(t_node **list)
{
	t_node	*curr;

	if ((*list) == NULL)
		return ;
	if ((*list)->next == NULL)
		return ;
	curr = (*list)->next;
	(*list)->next = (*list)->next->next;
	curr->next = (*list);
	*list = curr;
}

void	rrr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return ;
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return ;
	rrx(b_list);
	rrx(a_list);
}

void	rr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return ;
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return ;
	rx(a_list);
	rx(b_list);
}
