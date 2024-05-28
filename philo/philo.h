/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:25:31 by yiken             #+#    #+#             */
/*   Updated: 2024/05/22 12:41:38 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

# define PHILO_MAX	200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*death;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_data
{
	int				death_flag;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_data;

int		ft_atoi(char *str);
int		init_data(t_data *data, t_philo *philos);
int		init_forks(pthread_mutex_t *forks, int n);
void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks,
			char **av);
size_t	gettime_ms(void);
void	ft_usleep(size_t ms);
void	print_message(char *msg, t_philo *philo, int id);
void	create_threads(t_data *data);
void	eat_state(t_philo *philo);
void	sleep_state(t_philo *philo);
void	think_state(t_philo *philo);
int		is_dead(t_philo *philo);
void	*monitoring(void *arg);

#endif