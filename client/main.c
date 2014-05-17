/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:45:35 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/17 23:34:36 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

void					ft_use_client(char *s, char *s2)
{
	printf("Usage: client  %s <addr> %s <port>\n", s, s2);
	exit(0);
}

int						creat_client(char *n_addr, int port)
{
	int					sockt;
	struct protoent		*proto;
	struct sockaddr_in	direct;


	if (!(proto = getprotobyname("tcp")))
		return (-1);
	sockt = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	direct.sin_family = AF_INET;
	direct.sin_port = htons(port);
	direct.sin_addr.s_addr = inet_addr(n_addr);
	if (connect(sockt, (const struct sockaddr *)&direct, sizeof(direct)) == -1)
		return (-1);
	return (sockt);
}

int						main(int ac, char **av)
{
	int					sockt;
	char				buf[1024];
	// int					r;

	if (ac != 3)
		ft_use_client(av[0], av[1]);
	if (av[1])
		sockt = creat_client(av[1], ft_atoi(av[2]));
	ft_memset(buf, 0, sizeof(buf));
	// while ((r = read(sockt, buf, sizeof(buf)) > 0))
	// {
		if (send(sockt, buf, sizeof(buf), MSG_OOB) == -1)
		{
			ft_putendl("Error to send");
			return (-1);
		}
	// }
	close(sockt);
	return (0);
}