#include "philo.h"

static inline bool ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static void ft_check(char *str)
{

}

static inline bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

//i need to adjust the midel to suit the check of negative apearences and display an error then exit clean 
int	parse_args(char *str)
{
	const char	*nbr;
	
	while (ft_isspace(str))
		str++;
}
