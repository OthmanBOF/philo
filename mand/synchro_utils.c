#include "philo.h"

void	xait_all_threads(t_data *data)
{
	while (!get_bool(&data->mutex_data, &data->all_threads_ready))
		;
}
