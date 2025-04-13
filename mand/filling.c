#include "philo.h"

static void	fork_init(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->data->philo_num;
	if (philo->id % 2 == 0)
	{
	 	philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
	else
		philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
		philo->second_fork = &forks[philo_position];
}

static void	philo_init(t_data *data)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while (++i < data->philo_num)
	{
		philo = data->philo + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->data = data;
		mutex_safe(&philo->philo_mutex, INIT);
		fork_init(philo, data->fork, i);
	}
}

void	ft_fill(t_data *data)
{
	int	i;

	i = -1;
	data->threads_running_nbr = 0;
	data->end_simul = false;
	data->all_threads_ready = false;
	data->philo = malloc_safe(sizeof(t_philo) * data->philo_num);
	mutex_safe(&data->mutex_data, INIT);
	mutex_safe(&data->write_mutex, INIT);
	data->fork = malloc_safe(sizeof(t_fork) * data->philo_num);
	while (++i < data->philo_num)
	{
		mutex_safe(&data->fork[i].fork, INIT);
		data->fork[i].fork_id = i;
	}
	philo_init(data);
}
