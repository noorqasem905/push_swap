/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:15:46 by nqasem            #+#    #+#             */
/*   Updated: 2024/12/19 14:17:09 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int arr[] = {7, 1, 2, 9, 4, 3, 88, 23, 43, 45, 39};
	int size = sizeof(arr) / sizeof(arr[0]);
	int arr2[size];
	int sizee = size;
	int tmp;
	int i = 0;
	int k = 1, j = 0;

	while (1 <= ((sizee / 2)) - (i))
	{
		arr2[i] = arr[sizee - 1 - i];
		arr[sizee - 1 - i] = -11111111;
		// printf("%i\n", arr2[i]);
		// printf("-------------------------------------->%i\n", arr[i]);
		i++;
	}
	// printf("-------------------------------------->%i\n", arr[i]);

	while (arr[k])
	{
		if (arr[j] > arr[k])
		{
			tmp = arr[k];
			arr[k] = arr[j];
			arr[j] = tmp;
			printf("SWAP");
		}
		k += 2;
		j += 2;
	}
	k = 1;
	j = 0;
	while (arr2[k])
	{
		if (arr2[j] > arr2[k])
		{
			tmp = arr2[k];
			arr2[k] = arr2[j];
			arr2[j] = tmp;
			printf("SWAP");
		}
		k += 2;
		j += 2;
	}
	j = 1;
	k = 3;
	while (arr[k])
	{
		if (arr[j] > arr[k])
		{
		}
	}
	i = 0;
	while (arr2[i])
	{
		printf("-------------------------------------->%i\n", arr2[i]);

		i++;
	}
}