/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:16:25 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/12 18:16:35 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static void	check_max(char *arr, int *flag, t_node **node)
{
	size_t	sum;
	long	x;

	sum = 0;
	x = h_ft_atoi(arr, flag);
	if ((x > 2147483647 || x < -2147483648) || (sum > 10))
		*flag = 3;
	if (!(*flag))
		insertend(node, x);
}

void	h_in_pool(t_node **node, int *flag, char **argv)
{
	int		k;
	int		i;
	char	**arr;

	k = 0;
	i = 0;
	while (argv[++k] && !(*flag))
	{
		arr = ft_split(argv[k], ' ');
		if (!arr)
			(*flag) = 4;
		while (arr[i])
		{
			if (!(*flag))
				check_max(arr[i], flag, node);
			free(arr[i++]);
		}
		i = 0;
		free(arr);
	}
}

void	h_repeat_num(t_node **node)
{
	t_node			*cur;
	t_node			*cur2;
	unsigned int	num;

	cur = *node;
	while (cur)
	{
		cur2 = *node;
		num = 0;
		while (cur2)
		{
			if (cur2->x == cur->x)
			{
				if (num > 0)
				{
					frees(node);
					error_message(5);
					exit(5);
				}
				num++;
			}
			cur2 = cur2->next;
		}
		cur = cur->next;
	}
}

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (*src == NULL || !*src)
	{
		error_message(1);
		return ;
	}
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}
