/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/08 17:54:28 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_args(t_pro *process, char **argv)
{
	process->n_philos = ft_atoi(argv[1]);
	/*process->time_to_die = ft_atoi(argv[2]);
	process->time_to_eat = ft_atoi(argv[3]);
	process->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		process->n_meals = ft_atoi(argv[5]);
	else
		process->n_meals = -1;*/
	//printf("%d", process->n_philos);
	return (0);
}

void	*routine()
{
	printf("eating\n");
	return (0);
}

/* pthread_create starts/initiliazes a new thread in the calling process*/
long int	philosophers(t_pro *process)
{
	int			i;

	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_create(&process->philos[i].tid, NULL, &routine, 
			(void *)&process->philos[i]) != 0)
			return (3);
		i++;
	}
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_join(process->philos[i].tid, NULL) != 0)
			return (4);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_pro		process;

	if (argc < 2)
		return (1);
	process.philos = malloc(sizeof(t_phil) * process.n_philos);
	if (!process.philos)
		return (2);
	get_args(&process, argv);
	philosophers(&process);
	return (0);
}
