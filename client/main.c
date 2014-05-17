/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:45:35 by jbernabe          #+#    #+#             */
/*   Updated: 2014/02/08 21:56:39 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "client.h"

static void	get_string(char *str, int pid)
{
	size_t	i;
	size_t	len;
	int		max_value;

	i = 0;
	max_value = 128;
	len = ft_strlen(str);
	str[len] = '\n';
	while((i <= len))
	{
		while (max_value > 0)
		{
			if (str[i] & max_value)
			{
				kill(pid, SIGUSR1); 
			}
			else 
			{
				kill(pid, SIGUSR2); 
			}
			usleep(1000);
			max_value = max_value / 2;
		}
		max_value = 128;
		i++;
	}
}

int		get_pid(char *s)
{
	int	pid;

	if ((pid = ft_atoi(s)) == 0)
			return (0);
	return (pid);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		get_string(av[2], get_pid(av[1]));
	}
	else
		ft_putstr("\033[35m Too few arguments\033[0m");
	return (0);
}
