/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:34:23 by nfoughal          #+#    #+#             */
/*   Updated: 2023/03/12 14:57:16 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac)
{
	if (ac == 5 || ac == 6)
		return (1);
	else
		return (0);
}

int	if_char_using(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		if (av[i][j] == '0' && av[i][j + 1] == '\0')
			return (0);
		while (av[i][j])
		{
			if (av[i][j] == '\0')
				return (0);
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_struct(t_content *p, int ac, char **av)
{
	p->n_philo = ft_atoi(av[1]);
	p->t_die = ft_atoi(av[2]);
	p->t_eat = ft_atoi(av[3]);
	p->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		p->n_time = ft_atoi(av[5]);
}
