/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:12:39 by nfoughal          #+#    #+#             */
/*   Updated: 2023/03/11 22:39:44 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	curent_time(void)
{
	struct timeval	timestamp_in_ms;

	gettimeofday(&timestamp_in_ms, NULL);
	return (timestamp_in_ms.tv_sec * 1000 + timestamp_in_ms.tv_usec / 1000);
}

void	fork_print(t_philo *pp)
{
	int	f;

	f = pthread_mutex_lock(&(pp->data->print));
	if (f)
		return ;
	printf("%ld %d  has taken a fork\n", curent_time() - pp->data->t0, pp->id);
	pthread_mutex_unlock(&(pp->data->print));
}

void	eat_print(t_philo *pp)
{
	int	f;

	f = pthread_mutex_lock(&(pp->data->print));
	if (f)
		return ;
	printf("%ld %d is eating\n", curent_time() - pp->data->t0, pp->id);
	pthread_mutex_unlock(&(pp->data->print));
	pthread_mutex_lock(&pp->flg);
	pp->flag++;
	pthread_mutex_unlock(&pp->flg);
}

void	sleep_print(t_philo *pp)
{
	int	f;

	f = pthread_mutex_lock(&(pp->data->print));
	if (f)
		return ;
	printf("%ld %d is sleeping\n", curent_time() - pp->data->t0, pp->id);
	pthread_mutex_unlock(&(pp->data->print));
}

void	think_print(t_philo *pp)
{
	int	f;

	f = pthread_mutex_lock(&(pp->data->print));
	if (f)
		return ;
	printf("%ld %d is thinking\n", curent_time() - pp->data->t0, pp->id);
	pthread_mutex_unlock(&(pp->data->print));
}
