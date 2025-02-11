/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:29:38 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/11 23:42:22 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_node **lst)
{
	t_node		*current;
	int			i;

	current = *lst;
	i = 1;
	while (current && current->next)
	{
		if (i != current->pos)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

int	sort_rev(t_node **lst)
{
	t_node		*current;
	int			i;

	i = lstsize(*lst);
	if (i > 3)
		return (0);
	current = *lst;
	while (current && current->next)
	{
		if (i != current->pos)
			return (0);
		i--;
		current = current->next;
	}
	ft_sx(lst, 1);
	ft_rrx(lst, 1);
	return (1);
}

void	sort_three(t_node **lst)
{
	if ((*lst)->pos > (*lst)->next->pos)
		ft_sx(lst, 1);
	if ((*lst)->next->pos > ((*lst)->next->next->pos)
		&& (*lst)->pos > (*lst)->next->next->pos)
		ft_rrx(lst, 1);
	else if ((*lst)->next->pos > ((*lst)->next->next->pos)
		&& (*lst)->pos < (*lst)->next->next->pos)
	{
		ft_rrx(lst, 1);
		ft_sx(lst, 1);
	}
}

t_node	*check_min(t_node *lst)
{
	t_node	*current;
	t_node	*min;

	current = lst;
	min = current;
	current = current->next;
	while (current)
	{
		if (current->pos < min->pos)
			min = current;
		current = current->next;
	}
	return (min);
}

t_node	*check_max1(t_node *lst)
{
	t_node	*current;
	t_node	*max;

	current = lst;
	max = current;
	current = current->next;
	while (current)
	{
		if (current->pos > max->pos)
			max = current;
		current = current->next;
	}
	return (max);
}
