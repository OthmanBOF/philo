/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:47 by obouftou          #+#    #+#             */
/*   Updated: 2025/07/04 11:55:24 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	fork_init(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->data->philo_num;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
	if (philo->id % 2 != 0)
	{
		philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
		philo->second_fork = &forks[philo_position];
	}
}

static void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->philo_num)
	{
		philo = data->philo + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		mutex_safe(&philo->philo_mutex, INIT);
		philo->data = data;
		fork_init(philo, data->fork, i);
	}
}

int	ft_fill(t_data *data)
{
	int	i;

	i = -1;
	data->threads_running_nbr = 0;
	data->end_simul = false;
	data->all_threads_ready = false;
	data->philo = malloc_safe(sizeof(t_philo) * data->philo_num);
	if (!data->philo)
		return (1);
	data->fork = malloc_safe(sizeof(t_fork) * data->philo_num);
	if (!data->fork)
		return (free(data->philo), 1);
	mutex_safe(&data->mutex_data, INIT);
	mutex_safe(&data->write_mutex, INIT);
	while (++i < data->philo_num)
	{
		mutex_safe(&data->fork[i].fork, INIT);
		data->fork[i].fork_id = i;
	}
	philo_init(data);
	return (0);
}
