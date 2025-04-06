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

// inputr : ./philo 8 800 200 200 [5]
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
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thred_id;
}		t_philo;;

struct  s_data
{

	long    philo_num;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	meals_limit;
	long	start_simul;
	bool	end_simul;
	t_philo	*philo;
};


/* ****prototypes**** */

void	err_exit(const char *str);
void	parse_args(t_data *str, char **av);
void	*malloc_safe(size_t bytes);
