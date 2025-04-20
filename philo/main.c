/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:33:46 by nfoughal          #+#    #+#             */
/*   Updated: 2023/03/15 15:35:57 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_content	p;
	int			i;

	i = 0;
	if (check_args(ac) == 0)
	{
		write(2, "Error Arguments must be 5", 26);
		return (0);
	}
	if (if_char_using(ac, av) == 0)
	{
		write(2, "Error must use positif numbers only", 36);
		return (0);
	}
	fill_struct(&p, ac, av);
	curent_time();
	philosophers(&p, ac, i);
	usleep(100);
	return (0);
}
