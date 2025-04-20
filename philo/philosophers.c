/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:32:56 by nfoughal          #+#    #+#             */
/*   Updated: 2023/03/15 15:24:16 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_philo *pp, t_content *p, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(p->print), NULL);
	while (i < p->n_philo)
	{
		pthread_mutex_init(&pp[i].flg, NULL);
		pthread_mutex_init(&fork[i], NULL);
		pthread_mutex_init(&pp[i].mut, NULL);
		i++;
	}
}

void	*phrs(void *arg)
{
	t_philo	*pp;

	pp = (t_philo *)arg;
	if (pp->id % 2 != 0)
		ftsleep(2);
	while (1)
	{
		pthread_mutex_lock(pp->left);
		fork_print(pp);
		pthread_mutex_lock(pp->right);
		fork_print(pp);
		eat_print(pp);
		pthread_mutex_lock(&pp->mut);
		pp->last_eat = curent_time();
		pthread_mutex_unlock(&pp->mut);
		ftsleep(pp->data->t_eat);
		pthread_mutex_unlock(pp->left);
		pthread_mutex_unlock(pp->right);
		sleep_print(pp);
		ftsleep(pp->data->t_sleep);
	}
	return (NULL);
}

int	philo_creat(pthread_mutex_t *fork, t_content *p,
	t_philo *pp, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < p->n_philo)
	{
		pp[i].id = i + 1;
		pp[i].left = &fork[i];
		if (i == p->n_philo - 1)
			pp[i].right = &fork[0];
		else
			pp[i].right = &fork[i + 1];
		pp[i].data = p;
		pp[i].last_eat = curent_time();
		if (pthread_create(&threads[i], NULL, phrs, &pp[i]) != 0)
			return (0);
		if (pthread_detach(threads[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	destroy_all(pthread_mutex_t *fork, t_philo *pp, t_content *p)
{
	int	i;

	i = 0;
	while (i < p->n_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		pthread_mutex_destroy(&pp[i].mut);
		pthread_mutex_destroy(&pp[i].flg);
		i++;
	}
}

int	if_dead(pthread_mutex_t *fork, t_content *p, t_philo *pp, int i)
{
	while (1)
	{
		ftsleep(1);
		i = 0;
		while (i < p->n_philo)
		{
			pthread_mutex_lock(&pp[i].mut);
			if ((curent_time() - pp[i].last_eat > p->t_die)
				|| (p->c == 6 && min_eat(pp)))
			{
				if (curent_time() - pp[i].last_eat > p->t_die)
				{
					pthread_mutex_lock(&p->print);
					printf("%ld %d died\n", curent_time() - pp->data->t0,
						pp[i].id);
					ftsleep(100);
				}
				destroy_all(fork, pp, p);
				pthread_mutex_destroy(&pp->data->print);
				return (1);
			}
			pthread_mutex_unlock(&pp[i].mut);
			i++;
		}
	}
}
