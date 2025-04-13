#include "philo.h"

void	wait_all_threads(t_data *data)
{
	while (!get_bool(&data->mutex_data, &data->all_threads_ready))
		;
}

void	increase_long(t_mtx *mutex, long *val)
{
	mutex_safe(mutex, LOCK);
	(*val)++;
	mutex_safe(mutex, UNLOCK);
}


bool all_threads_running(t_mtx *mutex, long *threads, long philo_nbr)
{
	bool	ret;

	ret = false;
	mutex_safe(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	mutex_safe(mutex, UNLOCK);
	return (ret);
}

void	de_sync_philos(t_philo *philo)
{
	if (philo->data->philo_num % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}
