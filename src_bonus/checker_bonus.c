/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:16:32 by nqasem            #+#    #+#             */
/*   Updated: 2025/03/18 14:30:29 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_line(char *line, t_node **a_stack, t_node **b_stack)
{
	if (!ft_strcmp(line, "sa\n"))
		return (sx(a_stack));
	else if (!ft_strcmp(line, "sb\n"))
		return (sx(b_stack));
	else if (!ft_strcmp(line, "pa\n"))
		return (push(b_stack, a_stack));
	else if (!ft_strcmp(line, "pb\n"))
		return (push(a_stack, b_stack));
	else if (!ft_strcmp(line, "ra\n"))
		return (rx(a_stack));
	else if (!ft_strcmp(line, "rb\n"))
		return (rx(b_stack));
	else if (!ft_strcmp(line, "rr\n"))
		return (rr(a_stack, b_stack));
	else if (!ft_strcmp(line, "rra\n"))
		return (rrx(a_stack));
	else if (!ft_strcmp(line, "rrb\n"))
		return (rrx(b_stack));
	else if (!ft_strcmp(line, "rrr\n"))
		return (rrr(a_stack, b_stack));
	else
		return (1);
	return (0);
}

int	input(t_node **a_stack, t_node **b_stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_line(line, a_stack, b_stack))
		{
			error_message(99);
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	set_postion(*a_stack);
	if (check_sort(a_stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_node		*node;
	t_node		*cur;
	int			flag;

	node = NULL;
	cur = NULL;
	flag = 0;
	if (argc == 1)
		return (1);
	h_in_pool(&node, &flag, argv);
	if (flag)
	{
		frees(&node);
		error_message(flag);
		exit(flag);
	}
	h_repeat_num(&node);
	flag = input(&node, &cur);
	frees(&node);
	frees(&cur);
	return (flag);
}

/*
void print(t_node *list)
{
	while (list)
	{
		printf("%ld\n", list->x);
		list = list->next;
		sleep(0.3);
	}
}

void printpos(t_node *list)
{
	while (list)
	{
		printf("%i\n", list->cost);
		printf("---------->%ld\n", list->x);
		list = list->next;
		sleep(0.3);
	}
}
*/
