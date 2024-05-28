/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:58:37 by yiken             #+#    #+#             */
/*   Updated: 2024/05/20 17:28:56 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (gettime_ms() - philo->last_meal >= philo->time_to_die
		&& philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	philo_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (philo_died(&philos[i]))
		{
			print_message("died", &philos[i], i + 1);
			pthread_mutex_lock(philos[0].death_lock);
			*philos->death = 1;
			pthread_mutex_unlock(philos[0].death_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_ate(t_philo *philos)
{
	int	i;
	int	finished;

	if (philos[0].num_times_to_eat == -1)
		return (0);
	i = 0;
	finished = 0;
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[0].num_times_to_eat)
			finished++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].death_lock);
		*philos->death = 1;
		pthread_mutex_unlock(philos[0].death_lock);
		return (1);
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_philo	*philos;

	philos = arg;
	while (1)
	{
		if (philo_death(philos) || all_ate(philos))
			break ;
	}
	return (arg);
}
