/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:35:18 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/22 20:37:12 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_zombies(int	*id, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		printf("fork error");
		free(id);
	}
	while (j < i)
	{
		kill(id[j], SIGINT);
		j++;
	}
	free(id);
	printf("fork error");
}

void	kill_the_children(int *id, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		kill(id[i], SIGINT);
		i++;
	}
	free(id);
}
