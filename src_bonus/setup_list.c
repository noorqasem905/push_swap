/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:51:16 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/12 18:01:03 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	set_values(int *i, int *neg, long *c, int *j)
{
	*i = 0;
	*j = 0;
	*neg = 1;
	*c = 0;
}

long	h_ft_atoi(const char *str, int *flag)
{
	int		i;
	int		neg;
	long	c;
	int		j;

	set_values (&i, &neg, &c, &j);
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	j = i;
	while (str[i] && ft_isdigit(str[i]) && !(*flag))
	{
		c = (c * 10) + (str[i] - '0');
		if (c == 0)
			j++;
		i++;
	}
	if ((str[i] && !ft_isdigit(str[i])) || i - j > 10)
		*flag = ft_isdigit(str[i]) + 2;
	return (c * neg);
}

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

int	check_sort(t_node **lst)
{
	t_node		*current;
	int			i;

	current = *lst;
	i = current->x;
	while (current && current->next)
	{
		if (i != current->pos)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
