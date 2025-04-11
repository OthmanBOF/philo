# include "philo.h"

void	dinner_simul(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);
	while (!simulation_finished(philo->data))
	{
		if (philo->full)
			break ;
		
	}

	return (NULL);
}



void	dining(t_data *data)
{
	int	i;

	i = -1;
	if (data->meals_limit == 0)
		return ;
	else if (data->philo_num == 1)
		;//todo
	else
	{
	while (++i < data->philo_num)
		thread_safe(&data->philo[i].thred_id, dinner_simul,
			&data->philo[i], CREAT);
	}
	data->start_simul = gettime(MILLISECOND);
	set_bools(&data->mutex_data, &data->all_threads_ready, true);
	i = -1;
	while (++i < data->philo_num)
		thread_safe(data->philo[i].thred_id, NULL, NULL, JOIN);


}
