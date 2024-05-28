/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:41:17 by yiken             #+#    #+#             */
/*   Updated: 2024/05/19 15:07:23 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_state(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	sleep_state(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	eat_state(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo, philo->id);
	philo->is_eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = gettime_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
