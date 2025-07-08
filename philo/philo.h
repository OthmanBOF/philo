/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:08:10 by obouftou          #+#    #+#             */
/*   Updated: 2025/07/08 17:52:36 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <errno.h>

# define RST		"\033[0m"
# define BLACK   "\033[1;30m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"

# define PH_MAX 200

typedef enum s_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREAT,
	JOIN,
}		t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_time_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FOKR,
	TAKE_SECOND_FORK,
	DIED,
}		t_philo_status;

typedef pthread_mutex_t	t_mtx;

typedef struct s_data	t_data;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}		t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thred_id;
	t_mtx		philo_mutex;
	t_data		*data;
}		t_philo;

struct	s_data
{
	int			error_flag;
	long		philo_num;
	long		time_to_eat;
	long		time_to_die;
	long		time_to_sleep;
	long		meals_limit;
	long		threads_running_nbr;
	long		start_simul;
	bool		end_simul;
	pthread_t	monitor;
	t_mtx		mutex_data;
	t_mtx		write_mutex;
	bool		all_threads_ready;
	t_fork		*fork;
	t_philo		*philo;
};

int		*err_exit(const char *str);
void	parse_args(t_data *str, char **av);
void	*malloc_safe(size_t bytes);
int		mutex_safe(t_mtx *mutex, t_opcode opcode);
bool	thread_safe(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode opcode);
int		ft_fill(t_data *data);
bool	simulation_finished(t_data *data);
void	set_long(t_mtx *mutex, long *dest, long value);
long	get_long(t_mtx *mutex, long *value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_bools(t_mtx *mutex, bool *dest, bool value);
void	wait_all_threads(t_data *data);
long	gettime(t_time_code time_code);
void	precise_usleep(long usec, t_data *data);
void	write_status(t_philo_status status, t_philo *philo);
void	*monitor_dinner(void *data);
bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr);
void	increase_long(t_mtx *mutex, long *val);
void	clean(t_data *data);
void	thinking(t_philo *philo, bool pre_simul);
void	de_sync_philos(t_philo *philo);
void	dining(t_data *data);
void	*dinner_simul(void *data);
void	create_philos(t_data *data);

#endif