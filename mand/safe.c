#include "philo.h"

void	*malloc_safe(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		errno("malloc error <-_->");
	return (ret);
}