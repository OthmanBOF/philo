#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <errno.h>
/*
 * Usage: Include this header in your project to use ANSI color codes in printf.
 * Example:
 *     printf(BOLD_RED "Error: Something went wrong!\n" RESET);
 * Always use RESET at the end to avoid terminal color issues.
 */
#define RST		"\033[0m"
#define bLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

typedef enum s_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREAT,
	JOIN,
	DETACH,
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

typedef pthread_mutex_t t_mtx;

typedef struct s_data t_data;

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
	t_data		*data;
}		t_philo;;

struct  s_data
{
	long	philo_num;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	meals_limit;
	long	start_simul;
	bool	end_simul;
	t_mtx	mutex_data;
	t_mtx	write_mutex;
	bool	all_threads_ready;
	t_fork	*fork;
	t_philo	*philo;
};


/* ****prototypes**** */

void	err_exit(const char *str);
void	parse_args(t_data *str, char **av);
void	*malloc_safe(size_t bytes);
void	mutex_safe(t_mtx *mutex, t_opcode opcode);
void	thread_safe(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);
void	ft_fill(t_data *data);
bool	simulation_finished(t_data *data);
void	set_long(t_mtx *mutex,long *dest ,long *value);
long	get_long(t_mtx *mutex, long *value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_bools(t_mtx *mutex, bool *dest, bool value);
void	wait_all_threads(t_data *data);
long	gettime(t_time_code time_code);
void	precise_usleep(long usec, t_data *data);

