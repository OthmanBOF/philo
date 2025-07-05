/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:16:33 by obouftou          #+#    #+#             */
/*   Updated: 2025/07/05 14:05:42 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*malloc_safe(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
	{
		err_exit("ma beforelloc error <-_->");
		return (NULL);
	}
	return (ret);
}

static	void	mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		err_exit("The value specified by the mutex is invalid.");
	else if (EINVAL == status && INIT == opcode)
		err_exit("the value specified by attr is invalid.");
	else if (EINVAL == status && DESTROY == opcode)
		err_exit("The value specified by the mutex is invalid ");
	else if (EDEADLK == status)
		err_exit("A deadlock would occur if the thread blkd is mtx in need.");
	else if (EPERM == status)
		err_exit("the current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		err_exit("the processe cannot alloc enough memory to mtx.");
	else if (EBUSY == status)
		err_exit("the mutex is locked.");
}

int	mutex_safe(t_mtx *mutex, t_opcode opcode)
{
	if (!mutex)
	{
		err_exit("mutex_safe called with NULL mutex");
		return (1);
	}
	if (opcode == LOCK)
		mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
	{
		err_exit("wrong opcode for mutex_error");
		return (1);
	}
	return (0);
}

static void	threads_error(int status, t_opcode opcode)
{
	if (status != 0 && (opcode == CREAT || opcode == JOIN))
	{
		err_exit("Thread error");
		return ;
	}
}

void	thread_safe(pthread_t *thread, void *(*foo)(void *),
				void *data, t_opcode opcode)
{
	if (CREAT == opcode)
		threads_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		threads_error(pthread_join(*thread, NULL), opcode);
	else
	{
		err_exit("wrong opcode for thrade_safe:"
			"use: <CREAT> <JOIN>");
	}
}
