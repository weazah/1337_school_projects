/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:42:04 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/21 14:32:49 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_data(t_philos *philos)
{
	int			i;
	int			j;
	t_mutexes	*temp;
	t_mutexes	*tem;

	j = 0;
	i = philos[0].n_ph;
	temp = philos[0].mutexes;
	mutexes_destro(philos, i);
	pthread_mutex_destroy(&philos[0].mutexes->print);
	while (j < i)
	{
		tem = temp;
		free(tem);
		temp = temp->next;
		i--;
	}
	free(philos);
}

int	mutexes_destro(t_philos *philos, int rank)
{
	int	i;

	i = 0;
	if (!rank)
		return (0);
	while (i < rank)
	{
		pthread_mutex_destroy(&philos[i].mutexes->mutex);
		i++;
	}
	return (1);
}
