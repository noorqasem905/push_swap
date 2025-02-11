/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:54:21 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/11 23:59:26 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	frees(t_node **root)
{
	t_node	*cur;
	t_node	*cur2;

	cur = *root;
	while (cur != NULL)
	{
		cur2 = cur;
		cur = cur->next;
		free(cur2);
	}
	free(cur);
	*root = NULL;
}

void	error_message(int flag)
{
	if (flag == 1)
		write(1, "The stack is empty\n", 20);
	else if (flag == 2)
		write(1, "invalid input\n", 14);
	else if (flag == 3)
		write(1, "overflow input\n", 15);
}
