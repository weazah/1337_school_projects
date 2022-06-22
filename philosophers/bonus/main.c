/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:33:06 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/22 20:34:35 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("usage: ./philo philos death eat sleep [t_each_p_eats]\n");
		printf("	[t_each_ph_eats] is optional\n");
		return (0);
	}
	if (input_eval(av + 1) == 0)
		return (printf("\033[0;36minvalid args\n"), 1);
	start_sim(av + 1);
}
