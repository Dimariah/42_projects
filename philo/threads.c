/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:48:51 by yiken             #+#    #+#             */
/*   Updated: 2024/05/22 18:03:53 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_fail(t_data *data, int fail_type)
{
	if (fail_type == 1)
		write(2, "Failed to create thread\n", 24);
	if (fail_type == 2)
		write(2, "Failed to join thread\n", 22);
	pthread_mutex_lock(&data->death_lock);
	data->death_flag = 1;
	pthread_mutex_unlock(&data->death_lock);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->death)
		return (pthread_mutex_unlock(philo->death_lock), 1);
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

void	*life_cycle(void	*arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
	{
		print_message("is thinkin", philo, philo->id);
		ft_usleep(1);
	}
	while (!is_dead(philo))
	{
		eat_state(philo);
		sleep_state(philo);
		think_state(philo);
	}
	return (arg);
}

void	create_threads(t_data *data)
{
	pthread_t	monitor;
	int			i;

	if (pthread_create(&monitor, 0, monitoring, data->philos) != 0)
		handle_fail(data, 1);
	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, 0, life_cycle,
				&data->philos[i]) != 0)
			handle_fail(data, 1);
		i++;
	}
	if (pthread_join(monitor, 0) != 0)
		handle_fail(data, 2);
	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, 0) != 0)
			handle_fail(data, 2);
		i++;
	}
}
