/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:17:16 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/22 20:38:22 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mini_routine(t_ph *phil)
{
	eating(phil);
	sleeping(phil);
	thinking(phil);
}

void	philosophers(t_ph *phil, int *id, int i)
{
	free(id);
	phil->rank = i;
	if (phil->n_eat == -1)
		free_routine(phil);
	else
		routine(phil);
	exit(0);
}

void	fill_stamps(t_ph *phil)
{
	phil->current = what_time();
	phil->last_eat = what_time();
}

void	forking(t_ph phil)
{
	int	i;
	int	*id;

	id = malloc(phil.number * sizeof(int));
	if (!id)
		return ;
	i = 0;
	fill_stamps(&phil);
	while (i < phil.number)
	{
		id[i] = fork();
		if (id[i] == -1)
		{
			kill_zombies(id, i);
			return ;
		}
		if (id[i] == 0)
			philosophers(&phil, id, i);
		i++;
	}
	wait_func(phil, id);
	delete_sems(phil.sems);
}

void	wait_func(t_ph phil, int *id)
{
	sem_wait(phil.sems->death);
	if (phil.n_eat == -1)
	{
		sem_wait(phil.sems->death);
		kill_the_children(id, phil.number);
		return ;
	}
	else if (phil.n_eat)
	{
		launch_sem_th(phil.sems, id, phil.number);
	}
}
