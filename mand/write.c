#include "philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->data->start_simul;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	else
	{
		mutex_safe(&philo->data->write_mutex, LOCK);
		if ((TAKE_FIRST_FOKR == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->data))
			printf(GREEN"%-6ld"RST GREEN" %d has taken a fork\n"RST, elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d is eating\n", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf(RED"%-6ld"RST RED" %d died\n"RST, elapsed, philo->id);
	}
	mutex_safe(&philo->data->write_mutex, UNLOCK);
}
