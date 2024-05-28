/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:15:21 by yiken             #+#    #+#             */
/*   Updated: 2024/05/25 16:46:34 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *msg, t_philo *philo, int id)
{
	size_t	time;

	time = gettime_ms() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!is_dead(philo))
		printf("%zu %d %s\n", time, id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

void	ft_usleep(size_t ms)
{
	size_t	start;

	start = gettime_ms();
	while (gettime_ms() - start < ms)
		// usleep(500);
}

size_t	gettime_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, 0) != 0)
		write(2, "gettimeofday() fail\n", 20);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	tmp;

	i = 0;
	n = 0;
	tmp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		if (tmp > n)
			return (-1);
		tmp = n;
		i++;
	}
	return (n);
}
