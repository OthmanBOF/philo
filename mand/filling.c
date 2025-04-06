#include "philo.h"

void	ft_fill(t_data *data)
{
	data->end_simul = false;
	data->philo = malloc_safe(data->philo_num);
	
}