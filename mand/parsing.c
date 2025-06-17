/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:12:46 by obouftou          #+#    #+#             */
/*   Updated: 2025/06/17 17:14:22 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long	my_atol(t_data *data, const char *str)
{
	long	res;

	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
		return (0);
	if (!is_digit(*str))
		err_exit("only valid digitts ;)");
	res = 0;
	while (is_digit(*str))
		res = res * 10 + (*str++ - '0');
	while (*str)
	{
		if (!ft_isspace(*str))
			data->error_flag = 1;
		str++;
	}
	return (res);
}

static long	ft_check(t_data *data, char *str)
{
	long	input;

	input = my_atol(data, str);
	if (data->error_flag)
		return (0);
	if (input > INT_MAX)
	{
		err_exit("the INT_MAX is the limit G");
		data->error_flag = 1;
	}
	if (input < 1)
	{
		err_exit("Only positives G :)");
		data->error_flag = 1;
	}
	return (input);
}

void	parse_args(t_data *str, char **av)
{
	str->philo_num = ft_check(str, av[1]);
	if (str->philo_num > PH_MAX || str->philo_num < 1)
	{
		str->error_flag = 1;
		err_exit("exxeded the max philos 200 :)");
		return ;
	}
	str->time_to_die = ft_check(str, av[2]) * 1e3;
	str->time_to_eat = ft_check(str, av[3]) * 1e3;
	str->time_to_sleep = ft_check(str, av[4]) * 1e3;
	if (str->time_to_die < 6e4
		|| str->time_to_eat < 6e4
		|| str->time_to_sleep < 6e4)
	{
		err_exit("use timestamps major than 60ms");
		str->error_flag = 1;
	}
	if (av[5])
		str->meals_limit = ft_check(str, av[5]);
	else
		str->meals_limit = -1;
}
