#include "philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->data->start_simul;
	mutex_safe(&philo->data->write_mutex, LOCK);
	if (philo->full)
		return ;
	else
	{
		if ((TAKE_FIRST_FOKR == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d is eating\n", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d is thinking\n", elapsed, philo->id);
		else if (DIED == status && !simulation_finished(philo->data))
			printf(WHITE"%-6ld"RST" %d died\n", elapsed, philo->id);
	}
	mutex_safe(&philo->data->write_mutex, UNLOCK);
}
