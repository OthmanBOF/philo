#include "philo.h"

void	monitor_dinner(void *data)
{
	t_data	*table;

	table = (t_data *)data;
	while (! all_threads_running(&table->mutex_data, &table->threads_running_nbr, table->philo_num))
		;
	while (!simulation_finished(table))
	{
		
	}
	return (NULL);
}
