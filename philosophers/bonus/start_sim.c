/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:42:57 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/22 19:19:30 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	delete_sems(t_sem *sems)
{
	sem_unlink("fork");
	sem_unlink("death");
	sem_unlink("print");
	free(sems);
}

t_sem	*get_sema(int n)
{
	t_sem	*sems;

	sems = malloc(sizeof(t_sem));
	if (!sems)
		return (NULL);
	sem_unlink("fork");
	sem_unlink("death");
	sem_unlink("print");
	sems->fork = sem_open("fork", O_CREAT, 0777, n);
	sems->death = sem_open("death", O_CREAT, 0777, 1);
	sems->print = sem_open("print", O_CREAT, 0777, 1);
	if (sems->fork == SEM_FAILED || sems->fork == SEM_FAILED
		|| sems->print == SEM_FAILED)
		return (delete_sems(sems), NULL);
	return (sems);
}

void	start_sim(char	**av)
{
	t_ph	phil;

	phil.number = ft_atoi(av[0]);
	phil.t_die = ft_atoi(av[1]);
	phil.t_eat = ft_atoi(av[2]);
	phil.t_sleep = ft_atoi(av[3]);
	if (av[4] == NULL)
		phil.n_eat = -1;
	else
		phil.n_eat = ft_atoi(av[4]);
	phil.sems = get_sema(phil.number);
	if (phil.sems == NULL)
		return ;
	forking(phil);
}
