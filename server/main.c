/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 23:45:35 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/17 23:33:26 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "serveur.h"

void					ft_use(char *s)
{
	printf("Usage: server %s <port>\n", s);
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
	if (listen(sockt, MAX_CLIENT) == -1)
		exit(-1);
	return (sockt);
}

void					ft_read_client(int c_sock)
{
	int					r;
	char				buf[1024];

	r = 0;
	while (1)
	{
		r = recv(c_sock, buf, sizeof(buf), MSG_WAITALL);
		if (r <= -1)
		{
			printf("error recv");
			exit(0);
		}
		buf[r] = '\0';
		printf("%s\n", buf);
		ft_memset(buf, 0, sizeof(buf));
	}

}

int						main(int ac, char **av)
{
	int					sockt;
	int					csock;
	unsigned int		c_size;
	struct sockaddr_in	c_info;
	

	if (ac != 2)
		ft_use(av[0]);
	if (av[1])
		sockt = creat_server(ft_atoi(av[1]));
	c_size = sizeof(c_info);
	if ((csock = accept(sockt, (struct sockaddr *)&c_info, &c_size)) == -1)
		exit(-1);
	ft_read_client(csock);
	close(csock);
	close(sockt);
	return (0);
}
