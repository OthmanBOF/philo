#include "philo.h"

int main (int ac, char **av)
{
    t_data  data;

    if (ac == 5 || av == 6)
    {
        pars_args(&data, av);
        // creatin allocing for philos and meat 
        ft_fill(&data);
        // start the simulation 
        dining(&data);
        // exit no leaks if philos are fulll | or sadly one died 
        cleaner(&data); 
    }
    else
        err_exit("feed me well inputs bro:\n"
            GREEN"Correct is ./philo 8 800 200 200 5") ;// todo a function to display errors in std error field 
}