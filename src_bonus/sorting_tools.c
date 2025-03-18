/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:54:01 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/18 14:01:10 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	rrx(t_node **list)
{
	t_node	*prev;
	t_node	*cur;

	if ((*list) == NULL)
		return (1);
	if ((*list)->next == NULL)
		return (1);
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
	return (0);
}

int	rx(t_node **b_list)
{
	t_node	*curr;

	if ((*b_list) == NULL)
		return (1);
	if ((*b_list)->next == NULL)
		return (1);
	curr = *b_list;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = (*b_list);
	curr = (*b_list)->next;
	(*b_list)->next = NULL;
	*b_list = curr;
	return (0);
}

int	sx(t_node **list)
{
	t_node	*curr;

	if ((*list) == NULL)
		return (1);
	if ((*list)->next == NULL)
		return (1);
	curr = (*list)->next;
	(*list)->next = (*list)->next->next;
	curr->next = (*list);
	*list = curr;
	return (0);
}

int	rrr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return (1);
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return (1);
	rrx(b_list);
	rrx(a_list);
	return (0);
}

int	rr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return (1);
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return (1);
	rx(a_list);
	rx(b_list);
	return (0);
}
