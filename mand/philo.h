#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

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

typedef struct  s_data
{
	long    philo_num;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	meals_limit;
}		t_data;


/* ****prototypes**** */

void	errno(const char *str);
void	parse_args(t_data *str, char **av);
