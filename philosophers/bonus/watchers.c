/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:37:41 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/22 21:00:31 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watcher(void	*arg)
{
	t_ph	*phil;

	phil = (t_ph *)arg;
	while (1)
	{
		if (what_time() - phil->last_eat > phil->t_die)
		{
			sem_wait(phil->sems->print);
			printf("%lu ms %d died\n",
				what_time() - phil->current, phil->rank + 1);
			sem_post(phil->sems->death);
		}
	}
}

void	*free_watcher(void	*arg)
{
	t_ph	*phil;

	phil = (t_ph *)arg;
	while (1)
	{
		if (what_time() - phil->last_eat > phil->t_die)
		{
			sem_wait(phil->sems->print);
			printf("%lu ms %d died\n",
				what_time() - phil->current, phil->rank + 1);
			sem_post(phil->sems->death);
		}
	}
}

void	*sem_watch(void *arg)
{
	t_temp	*temp;

	temp = (t_temp *) arg;
	sem_wait(temp->sems->death);
	kill_the_children(temp->id, temp->n);
	return (NULL);
}

void	launch_sem_th(t_sem *sems, int *id, int n)
{
	pthread_t	thread;
	t_temp		temp;
	int			i;

	i = 0;
	temp.id = id;
	temp.n = n;
	temp.sems = sems;
	if (pthread_create(&thread, NULL, &sem_watch, &temp) == -1)
	{
		printf("thread error\n");
		kill(0, SIGKILL);
	}
	pthread_detach(thread);
	while (i < n)
	{
		waitpid(id[i], 0, 0);
		i++;
	}
}
