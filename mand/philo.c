#include "philo.h"

int main (int ac, char **av)
{
	t_data  data;

	if (ac == 5 || av == 6)
	{
		pars_args(&data, av);
		ft_fill(&data);
		dining(&data);
		cleaner(&data);
	}
	else
		err_exit("feed me well inputs bro:\n"
			GREEN"Correct is ./philo 8 800 200 200 5") ;
}
