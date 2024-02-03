/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:25:23 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/04 00:33:06 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_error(int ac, char *argv)
{
    int    i;

    i = 0;
    if (ac != 3)
    {
        ft_putstr_fd("I don' work this way, give me two input. (PID; String)\n", 2);
        return (0);
    }
    if (ft_atoi(argv) < 0)
    {
        ft_putstr_fd("Error: Invalid PID\n", 2);
        return (0);
    }
    while (argv[i])
    {
        if (!ft_isdigit(argv[i]))
        {
            ft_putstr_fd("Error: Invalid PID\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
}

static void	send_bit(pid_t pid, char c)
{
    int	i;

    i = 7;
    while (i >= 0)
    {
        if ( c & (1 << i))
        {
            kill(pid, SIGUSR1);
            usleep(150);
        }
        else
        {
            kill(pid, SIGUSR2);
            usleep(150);
        }
        i--;
        usleep(150);

    }
}

int	main(int ac, char **argv)
{
	pid_t	pid;
	int		i;
    int     j;

	if (!check_error(ac, argv[1]))
		return (0);
    pid = ft_atoi(argv[1]);
    i = 0;
    while (argv[2][i])
        send_bit(pid, argv[2][i++]);
    j = 0;
    while (j < 8)
    {
        kill(pid, SIGUSR2);
        usleep(150);
        j++;
    }
    
	return (0);
}