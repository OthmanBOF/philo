# include "philo.h"

static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo);
}

void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	set_long(&philo->data->mutex_data, &philo->last_meal_time,gettime(MILLISECOND));
	increase_long(&philo->data->mutex_data, &philo->data->threads_running_nbr);
	write_status(TAKE_FIRST_FOKR, philo);
	while (!simulation_finished(philo->data))
		usleep(200);
	return (NULL);
}


static void	eat(t_philo *philo)
{
	mutex_safe(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FOKR, philo);
	mutex_safe(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, philo->last_meal_time, gettime(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->meals_limit > 0
			&& philo->meals_counter == philo->data->meals_limit)
		set_bools(&philo->philo_mutex, &philo->full, true);
	mutex_safe(&philo->first_fork->fork, UNLOCK);
	mutex_safe(&philo->second_fork->fork, UNLOCK);
}

void	dinner_simul(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
			gettime(MILLISECOND));
	increase_long(&philo->data->mutex_data, &philo->data->threads_running_nbr);
	while (!simulation_finished(philo->data))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo);
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
		thread_safe(&data->philo[0].thred_id, lone_philo, &data->philo[0], CREAT);
	else
	{
	while (++i < data->philo_num)
		thread_safe(&data->philo[i].thred_id, dinner_simul,
			&data->philo[i], CREAT);
	}
	thread_safe(&data->monitor, monitor_dinner, data, CREAT);
	data->start_simul = gettime(MILLISECOND);
	set_bools(&data->mutex_data, &data->all_threads_ready, true);
	i = -1;
	while (++i < data->philo_num)
		thread_safe(data->philo[i].thred_id, NULL, NULL, JOIN);
}
