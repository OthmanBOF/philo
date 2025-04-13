#include "philo.h"

int main (int ac, char **av)
{
	t_data  data;

	if (ac == 5 || ac == 6)
	{
		parse_args(&data, av);
		ft_fill(&data);
		dining(&data);
		clean(&data);
	}
	else
		err_exit("feed me well inputs bro:\n"
			GREEN"Correct is ./philo 8 800 200 200 5") ;
}
