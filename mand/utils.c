#include <philo.h>

void    err_exit(const char *str)
{
    printf(RED "%s\n" RST, str);
    exit(EXIT_FAILURE);
}