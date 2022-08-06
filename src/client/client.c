/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:48:28 by gmachado          #+#    #+#             */
/*   Updated: 2022/08/06 02:59:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	send_char(int pid, char ch)
{
	int	pos;

	pos = 7;
	while (pos >= 0)
	{
		if (ch & (1 << pos--))
		{
			if (kill(pid, SIGUSR2))
				send_error(pid, SIGUSR2);
		}
		else
		{
			if (kill(pid, SIGUSR1))
				send_error(pid, SIGUSR1);
		}
		usleep(WAIT_TIME);
	}
}

int	main(int argc, char *argv[])
{
	char	*current;
	int		pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID of server> \"message\"\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	current = argv[2];
	while (*current != '\0')
		send_char(pid, *current++);
	send_char(pid, '\0');
}
