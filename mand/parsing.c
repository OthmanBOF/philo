#include "philo.h"

static inline bool ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static inline bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static char  *ft_check(const char *str)
{
	int	len;
	const char	*num;

	len = 0;
	while (ft_isspace)
		str++;
	if (str == '+')
		str++;
	else if (str == '-')
		err_exit("only positives :( G");
	if (!is_digit)
		err_exit("only valid numbers");
	num = str;
	while (*str++)
		len++;
	if (len > 10)
		err_exit("only the int range is allowed");
	return (num);
}

static long	atol(const char *str)
{
	long	res;

	res = 0;
	str = ft_check(str);
	while (is_digit(str))
		res = res * 10 + (*str++ - '0');
	if (res > INT_MAX)
		err_exit("INT_MAX is the maximum");
	return (res);
}


//i need to adjust the midel to suit the check of negative apearences and display an error then exit clean 
void	parse_args(t_data *str, char **av) 
{
	str->philo_num = atol(av[1]);
	str->time_to_die = atol(av[2]) * 1e3;
	str->time_to_eat = atol(av[3]) * 1e3;
	str->time_to_sleep = atol(av[4]) * 1e3;
	if (str->time_to_die < 6e4 
		|| str->time_to_eat < 6e4 
		|| str->time_to_sleep < 6e4 )
		err_exit("use timestamps major than 60ms");
	if (av[5])
		str->meals_limit = atol(av[5]);
	else
		str->meals_limit = -1;
}
