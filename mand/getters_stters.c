/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_stters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:11:52 by obouftou          #+#    #+#             */
/*   Updated: 2025/06/17 17:11:54 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bools(t_mtx *mutex, bool *dest, bool value)
{
	mutex_safe(mutex, LOCK);
	*dest = value;
	mutex_safe(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	mutex_safe(mutex, LOCK);
	ret = *value;
	mutex_safe(mutex, UNLOCK);
	return (ret);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	mutex_safe(mutex, LOCK);
	ret = *value;
	mutex_safe(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	mutex_safe(mutex, LOCK);
	*dest = value;
	mutex_safe(mutex, UNLOCK);
}

bool	simulation_finished(t_data *data)
{
	return (get_bool(&data->mutex_data, &data->end_simul));
}
