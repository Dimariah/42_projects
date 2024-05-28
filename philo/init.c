/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:30:15 by yiken             #+#    #+#             */
/*   Updated: 2024/05/19 17:00:12 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_from_data(t_philo *philo, t_data *data, char **av)
{
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->num_of_philos = ft_atoi(av[1]);
	if (av[5])
		philo->num_times_to_eat = ft_atoi(av[5]);
	else
		philo->num_times_to_eat = -1;
	philo->death = &data->death_flag;
	philo->death_lock = &data->death_lock;
	philo->meal_lock = &data->meal_lock;
	philo->write_lock = &data->write_lock;
}

void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks,
	char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].meals_eaten = 0;
		init_from_data(&philos[i], data, av);
		philos[i].start_time = gettime_ms();
		philos[i].last_meal = gettime_ms();
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

int	init_forks(pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(forks + i, 0) != 0)
			break ;
		i++;
	}
	while (i != n)
	{
		pthread_mutex_destroy(forks + --i);
		if (i == 0)
			return (0);
	}
	return (1);
}

int	init_data(t_data *data, t_philo *philos)
{
	data->death_flag = 0;
	data->philos = philos;
	if (pthread_mutex_init(&data->death_lock, 0) != 0)
		return (0);
	if (pthread_mutex_init(&data->meal_lock, 0) != 0)
		return (pthread_mutex_destroy(&data->death_lock), 0);
	if (pthread_mutex_init(&data->write_lock, 0) != 0)
	{
		pthread_mutex_destroy(&data->meal_lock);
		return (pthread_mutex_destroy(&data->death_lock), 0);
	}
	return (1);
}
