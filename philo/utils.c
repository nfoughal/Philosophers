/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:15:21 by nfoughal          #+#    #+#             */
/*   Updated: 2023/03/11 20:34:23 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		i;
	int		nb;
	int		s;

	nb = 0;
	i = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (s * nb);
}

int	min_eat(t_philo *pp)
{
	int	i;

	i = 0;
	while (i < pp->data->n_philo)
	{
		pthread_mutex_lock(&pp[i].flg);
		if (pp[i].flag < pp->data->n_time)
		{
			pthread_mutex_unlock(&pp[i].flg);
			return (0);
		}
		pthread_mutex_unlock(&pp[i].flg);
		i++;
	}
	return (1);
}

void	ftsleep(long time)
{
	long	start;

	start = curent_time();
	while (curent_time() < (start + time))
		usleep(100);
}
