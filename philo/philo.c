/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:48:15 by nfoughal          #+#    #+#             */
/*   Updated: 2023/03/11 22:33:06 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(t_content *p, int ac, int i)
{
	pthread_t		*threads;
	pthread_mutex_t	*fork;
	t_philo			*pp;

	threads = malloc(sizeof(pthread_t) * p->n_philo);
	fork = malloc(sizeof(pthread_mutex_t) * p->n_philo);
	pp = malloc(sizeof(t_philo) * p->n_philo);
	if (!threads || !fork || !pp)
		return (free(threads), free(fork), free(pp), 0);
	p->t0 = curent_time();
	p->c = ac;
	pp->flag = 0;
	mutex_init(pp, p, fork);
	if (!philo_creat(fork, p, pp, threads))
	{
		free(threads);
		free(fork);
		free(pp);
		return (0);
	}
	if_dead(fork, p, pp, i);
	free(threads);
	free(fork);
	free(pp);
	return (1);
}
