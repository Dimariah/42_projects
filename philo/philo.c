/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:04:59 by yiken             #+#    #+#             */
/*   Updated: 2024/05/22 12:33:17 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(pthread_mutex_t *forks, t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(forks + i);
		i++;
	}
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
}

int	invalid_content(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int	invalid_args(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0
		|| invalid_content(av[1]))
		return (write(2, "Invalid philosophers number\n", 28), 1);
	if (ft_atoi(av[2]) <= 0 || invalid_content(av[2]))
		return (write(2, "Invalid time to die\n", 20), 1);
	if (ft_atoi(av[3]) <= 0 || invalid_content(av[3]))
		return (write(2, "Invalid time to eat\n", 20), 1);
	if (ft_atoi(av[4]) <= 0 || invalid_content(av[4]))
		return (write(2, "Invalid time to sleep\n", 22), 1);
	if (av[5] && (ft_atoi(av[5]) < 0 || invalid_content(av[5])))
		return (write(2, "Invalid number of times each philosopher must eat\n",
				50), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac < 5 || ac > 6)
		return (write(2, "Wrong argument number\n", 22), 1);
	if (invalid_args(av))
		return (2);
	if (av[5] && ft_atoi(av[5]) == 0)
		return (0);
	if (!init_data(&data, philos) || !init_forks(forks, ft_atoi(av[1])))
		return (write(2, "Mutex initialization failed\n", 28), 1);
	init_philos(philos, &data, forks, av);
	create_threads(&data);
	destroy_mutexes(forks, &data, ft_atoi(av[1]));
	return (0);
}
