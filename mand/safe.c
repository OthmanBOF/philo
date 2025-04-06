#include "philo.h"

void	*malloc_safe(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		err_exit("malloc error <-_->");
	return (ret);
}

static	void mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		err_exit("The value specified by the mutex is invalid.");
	else if (EINVAL == status && INIT == opcode)
		err_exit("the value specified by attr is invalid.");
	else if (EINVAL == status && DESTROY == opcode)
		err_exit("The value specified by the mutex is invalid (possibly not initialized or already destroyed).");
	else if (EDEADLK == status)
		err_exit("A deadlock would occur if the thread blocked is waiting for mutex.");
	else if (EPERM == status)
		err_exit("the current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		err_exit("the processe cannot alloc enough memory to creat another mutex.");
	else if (EBUSY == status)
		err_exit("the mutex is locked.");
}
void	mutex_safe(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		err_exit("wrong opcode for mutex_error");
}