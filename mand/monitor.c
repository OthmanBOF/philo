#include "philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
	t_to_die = philo->data->time_to_die / 1e3;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int	i;
	t_data	*table;

	table = (t_data *)data;
	while (!all_threads_running(&table->mutex_data, &table->threads_running_nbr, table->philo_num))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table->philo_num && !get_bool(&table->mutex_data,
					&table->end_simul))
		{
			if (philo_died(table->philo + i))
			{
				set_bools(&table->mutex_data, &table->end_simul, true);
				write_status(DIED, table->philo + i);
			}
		}
	}
	return (NULL);
}
