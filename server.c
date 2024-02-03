/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:25:03 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/03 23:57:26 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	print_buffer(char *buffer, char c, int *index)
{
	buffer[*index] = c;
	(*index)++;
	if (c == '\0')
	{
		ft_putstr_fd(buffer, 1);
		write(1, "\n", 1);
		*index = 0;
	}
	return (*index);
}

static bool	check_signal(int signum, char *c, int *i)
{
	if (signum == SIGUSR2)
		*c = *c << 1;
	else if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	(*i)++;
	return (*i == 8);
}

void	sig_handler(int signum)
{
	static int	i = 0;
	static char	c = 0;
	static bool	d;
	static int	index = 0;
	static char	buffer[10000];

	d = check_signal(signum, &c, &i);
	if (d)
	{
		index = print_buffer(buffer, c, &index);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_putnbr_fd(pid, 1 );
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}