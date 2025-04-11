#include <philo.h>

void	err_exit(const char *str)
{
	printf(RED "%s\n" RST, str);
	exit(EXIT_FAILURE);
}

long	gettime(t_time_code time_code)
{
	struct	timeval	tv;
	gettimeofday(&tv, NULL);
}
