/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movmen_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:54:01 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/11 21:31:19 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_node **list, int which)
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
	if (which == 1)
		write(1, "rra\n", 4);
	else if (which == 0)
		write(1, "rrb\n", 4);
}

void	ft_rx(t_node **b_list, int which)
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
	if (which == 1)
		write(1, "ra\n", 3);
	else if (which == 0)
		write(1, "rb\n", 3);
}

void	ft_sx(t_node **list, int which)
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
	if (which == 1)
		write(1, "sa\n", 3);
	else if (which == 0)
		write(1, "sb\n", 3);
}

void	ft_rrr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return ;
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return ;
	ft_rrx(b_list, 5);
	ft_rrx(a_list, 5);
	write(1, "rrr\n", 4);
}

void	ft_rr(t_node **a_list, t_node **b_list)
{
	if ((*a_list) == NULL || (*b_list) == NULL)
		return ;
	if ((*a_list)->next == NULL || (*b_list)->next == NULL)
		return ;
	ft_rx(a_list, 5);
	ft_rx(b_list, 5);
	write(1, "rr\n", 3);
}
