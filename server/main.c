/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 23:45:35 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/17 05:16:47 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "serveur.h"

void					ft_use(char *s)
{
	printf("Usage: %s <port>\n", s);
	exit(0);
}

int						creat_server(int port)
{
	int					sockt;
	struct protoent		*proto;
	struct sockaddr_in	sin;


	if (!(proto = getprotobyname("tcp")))
		return (-1);
	sockt = 	socket(AF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockt, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (-1);
	listen(sockt, MAX_CLIENT);
	return (sockt);
}

int						main(int ac, char **av)
{
	int					sockt;
	int					csock;
	unsigned int		c_size;
	struct sockaddr_in	c_info;
	int					r;
	char				buf[1024];

	if (ac != 2)
		ft_use(av[0]);
	if (av[1])
		sockt = creat_server(ft_atoi(av[1]));
	c_size = sizeof(c_info);
	if ((csock = accept(sockt, (struct sockaddr *)&c_info, &c_size)) == -1)
		exit(-1);
	r = 0;
	while ((r = read(csock, buf, 1023)) > 0)
	{
		if (r > 0)
		{
			buf[r] = '\0';
			printf("data received %s\n", buf);
		}
	}
	close(csock);
	close(sockt);
	return (0);
}
