/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:51:16 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/13 22:41:30 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_node *lst)
{
	int		counter;
	t_node	*temp;

	while (!lst)
		return (0);
	counter = 1;
	temp = (t_node *)lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
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
		if (str[i++] == '-')
			neg *= -1;
	j = i;
	while (str[i] && ft_isdigit(str[i]) && !(*flag))
	{
		c = (c * 10) + (str[i] - '0');
		if (c == 0)
			j++;
		i++;
	}
	if ((str[i] && !ft_isdigit(str[i])) || i - j > 10 || str[i - 1] == '-'
		|| str[i - 1] == '+')
		*flag = ft_isdigit(str[i]) + 2;
	return (c * neg);
}

void	insertend(t_node **root, long new_value, int *flag)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		*flag = ENOMEM;
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
