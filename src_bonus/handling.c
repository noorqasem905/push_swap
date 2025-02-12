/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:54:21 by nqasem            #+#    #+#             */
/*   Updated: 2025/02/12 16:15:16 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	error_message(int flag)
{
	if (flag == 1)
		write(1, "The stack is empty\n", 20);
	else if (flag == 2)
		write(1, "Invalid Input\n", 14);
	else if (flag == 3)
		write(1, "Overflow Input\n", 15);
	else if (flag == 4)
		write(1, "No Memory Location\n", 20);
	else if (flag == 5)
		write(1, "Repeated Number\n", 16);
	else
		write(1, "Error\n", 7);
	return (flag);
}
