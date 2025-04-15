
#include "mand/philo.h"

// static inline bool ft_isspace(char c)
// {
// 	return ((c >= 9 && c <= 13) || c == 32);
// }

// static inline bool is_digit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }

// static char  *ft_check(const char *str)
// {
// 	int		len;
// 	const char	*num;

// 	len = 0;
// 	while (ft_isspace(*str))
// 		str++;
// 	if (*str == '+')
// 		str++;
// 	else if (*str == '-')
// 	{
// 		printf("only positives :( G");
// 		return(0);
// 	}
// 	if (!is_digit(*str))
// 	{
// 		printf("only valid numbers");
// 	}
// 	num = str;
// 	while (*str++)
// 		len++;
// 	if (len > 10)
// 		printf("only the int range is allowed");
// 	return ((char *)num);
// }

// static long	my_atol(const char *str)
// {
// 	long	res;
// 	char	*str2;
// 	res = 0;
// 	str2 = ft_check(str);
// 	if (!str2)
// 		return (0);
// 	while (is_digit(*str2))
// 		res = res * 10 + (*str2++ - '0');
// 	if (res > INT_MAX)
// 	{
// 		printf("INT_MAX is the maximum");
// 		return (0);
// 	}
// 	return (res);
// }
