/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/23 18:09:42 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define MAX_PHILO 200;
# define FORK "has taken a fork";
# define EAT "is eating";
# define SLEEP "is sleeping";
# define THINK "is thinking";
# define DEAD "died";

typedef struct s_phil
{
	int			id;
	pthread_t	tid;
	int			left_fork;
	int			right_fork;
	int			last_meal;
}	t_phil;

typedef struct s_pro
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	pthread_mutex_t	*fork;
	t_phil			*philos;
}		t_pro;

/* utils */
long	ft_atoi(char *nptr);

/* error check */

/* main */
int			get_args(t_pro *process, char **argv);
long		philosophers(t_pro *process);
void 		*routine();
long long	get_time(void);
void 		eat_philo(t_pro *process);
void 		fork_init(t_pro *process);

#endif
