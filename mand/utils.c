#include <philo.h>

void    errno(const char *str)
{
    printf(RED "%s\n" RST, str);
    exit(EXIT_FAILURE);
}