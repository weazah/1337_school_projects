/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:54:03 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/22 20:34:58 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_ph *phil)
{
	sem_wait(phil->sems->print);
	printf("%lu ms %d sleeping\n",
		(what_time() - phil->current), phil->rank + 1);
	sem_post(phil->sems->print);
	ft_usleep(phil->t_sleep);
}

void	thinking(t_ph *phil)
{
	sem_wait(phil->sems->print);
	printf("%lu ms %d is thinking\n",
		(what_time() - phil->current), phil->rank + 1);
	sem_post(phil->sems->print);
}

void	eating(t_ph *phil)
{
	sem_wait(phil->sems->fork);
	sem_wait(phil->sems->print);
	printf("%lu ms %d has taken a left fork\n",
		(what_time() - phil->current), phil->rank + 1);
	sem_post(phil->sems->print);
	sem_wait(phil->sems->fork);
	sem_wait(phil->sems->print);
	printf("%lu ms %d has taken a right fork\n",
		(what_time() - phil->current), phil->rank + 1);
	printf("%lu ms %d is eating\n",
		(what_time() - phil->current), phil->rank + 1);
	sem_post(phil->sems->print);
	phil->last_eat = what_time();
	ft_usleep(phil->t_eat);
	sem_post(phil->sems->fork);
	sem_post(phil->sems->fork);
}

void	free_routine(t_ph *phil)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &free_watcher, (void *) phil) == -1)
	{
		printf("thread error\n");
		return ;
	}
	pthread_detach(thread);
	while (1)
	{
		mini_routine(phil);
	}
}

void	routine(t_ph *phil)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &watcher, (void *) phil) == -1)
	{
		printf("thread error\n");
		return ;
	}
	pthread_detach(thread);
	while (phil->n_eat)
	{
		mini_routine(phil);
		phil->n_eat--;
	}
}
