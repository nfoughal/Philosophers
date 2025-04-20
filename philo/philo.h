/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:17:41 by nfoughal          #+#    #+#             */
/*   Updated: 2023/03/11 22:32:54 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<pthread.h>
# include <sys/time.h>

typedef struct s_content
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_time;
	pthread_mutex_t	print;
	long			t0;
	int				c;
}t_content;

typedef struct s_philo
{
	t_content		*data;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	mut;
	pthread_mutex_t	flg;
	long			last_eat;
	int				id;
	int				flag;
}t_philo;

int		check_args(int ac);
int		if_char_using(int ac, char **av);
int		ft_atoi(char *str);
void	fill_struct(t_content *p, int ac, char **av);
int		philosophers(t_content *p, int ac, int i);
void	*phrs(void *arg);
long	curent_time(void);
void	fork_print(t_philo *pp);
void	eat_print(t_philo *pp);
void	sleep_print(t_philo *pp);
void	think_print(t_philo *pp);
void	mutex_init(t_philo *pp, t_content *p, pthread_mutex_t *fork);
int		philo_creat(pthread_mutex_t *fork, t_content *p,
			t_philo *pp, pthread_t *threads);
int		if_dead(pthread_mutex_t *fork, t_content *p, t_philo *pp, int ac);
void	destroy_all(pthread_mutex_t *fork, t_philo *pp, t_content *p);
int		min_eat(t_philo *pp);
void	ftsleep(long time);

#endif