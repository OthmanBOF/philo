#include <philo.h>

void	err_exit(const char *str)
{
	printf(RED "%s\n" RST, str);
	exit(EXIT_FAILURE);
}

long	gettime(t_time_code time_code)
{
	struct	timeval	tv;
	if (gettimeofday(&tv, NULL));
		err_exit("Gettimeofdayfailed");
	if (SECOND == time_code)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == time_code)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		err_exit("WRong input to gettime");
	return (1337);
}


//presice usleep cause the original is not good for this project

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < usec)
	{
		if (simulation_finished(data))
			break ;
		elapsed = gettime(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep (rem / 2);
		else
		{
			while (gettime(MICROSECOND) - start < usec)
				;
		}
	}
}

