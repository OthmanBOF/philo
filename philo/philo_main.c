/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:14:43 by obouftou          #+#    #+#             */
/*   Updated: 2025/07/07 17:03:32 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		data.error_flag = 0;
		parse_args(&data, av);
		if (!data.error_flag)
		{
			if (ft_fill(&data) == 1)
				return (1);
			dining(&data);
			clean(&data);
		}
		else
			return (1);
	}
	else
		err_exit(RED"feed me well inputs bro:\n"
			GREEN"Correct is ./philo 8 800 200 200 5");
	return (0);
}
