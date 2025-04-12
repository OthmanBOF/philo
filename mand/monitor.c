#include "philo.h"

void	monitor_dinner(void *data)
{
	int	i;
	t_data	*table;

	table = (t_data *)data;
	while (! all_threads_running(&table->mutex_data, &table->threads_running_nbr, table->philo_num))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table->philo_num)
		{
			if (philo_died(table->philo + i))
			{
				set_bools(&table->mutex_data, &table->end_simul, true);
				write_status(DIED, )
			}
		}
	}
	return (NULL);
}
