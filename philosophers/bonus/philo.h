/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:33:35 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/22 20:58:45 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <signal.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_sem
{
	sem_t	*fork;
	sem_t	*death;
	sem_t	*print;
}	t_sem;

typedef struct s_ph
{
	int		number;
	int		rank;
	long	t_eat;
	long	t_die;
	long	t_sleep;
	long	current;
	long	last_eat;
	int		n_eat;
	t_sem	*sems;

}	t_ph;

typedef struct s_temp
{
	int		*id;
	int		n;
	t_sem	*sems;
}	t_temp;

t_sem	*get_sema(int n);
int		input_eval(char **av);
void	kill_zombies(int	*id, int i);
void	kill_the_children(int *id, int n);
void	sleeping(t_ph *phil);
void	thinking(t_ph *phil);
void	eating(t_ph *phil);
void	free_routine(t_ph *phil);
void	routine(t_ph *phil);
void	mini_routine(t_ph *phil);
void	philosophers(t_ph *phil, int *id, int i);
void	fill_stamps(t_ph *phil);
void	forking(t_ph phil);
void	wait_func(t_ph phil, int *id);
void	delete_sems(t_sem *sems);
void	start_sim(char	**av);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
long	what_time(void);
void	ft_usleep(long ms);
void	*watcher(void	*arg);
void	*free_watcher(void	*arg);
void	*sem_watch(void *arg);
void	launch_sem_th(t_sem *sems, int *id, int n);

#endif
