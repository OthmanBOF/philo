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

static void	threads_error(int status, t_opcode opcode)
{
	if(status == 0)
		return ;
	if (EAGAIN == status)
		err_exit("no resources to creat another thread");
	else if (EPERM == status)
		err_exit("the caller does not have the right permissions");
	else if (EINVAL == status && CREAT == opcode)
		err_exit("the value specified by the attr is invalid");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		err_exit("the value specified by the thread is not joinable");
	else if (status == ESRCH)
		err_exit("no thread could be found corresponding to that"
		"specified by thr given thread ID, thread");
	else if (status == EDEADLK)
			err_exit("A deadlock was detected or thr value of"
			"thread specifiesthe calling thread");
}

void	thread_safe(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
	if (CREAT == opcode)
		threads_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		threads_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		threads_error(pthread_detach(*thread), opcode);
	else
		err_exit("wrong opcode for thrade_safe:"
		"use: <CREAT> <JOIN> <DETACH>");
}
