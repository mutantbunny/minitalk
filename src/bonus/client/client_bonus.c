/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:48:28 by gmachado          #+#    #+#             */
/*   Updated: 2022/08/06 14:10:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>

int	g_ready;

static void	send_char(int pid, char ch)
{
	int	pos;

	pos = 7;
	while (pos >= 0)
	{
		if (g_ready)
		{
			g_ready = 0;
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
		}
	}
}

static void	response_handler(int sig_num)
{
	(void)sig_num;
	g_ready = 1;
}

int	initialize_handler(struct sigaction *action)
{
	action->sa_handler = response_handler;
	if (sigemptyset(&(action->sa_mask)) || sigaction(SIGUSR1, action, NULL))
	{
		ft_printf("Error setting up signal handlers");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char				*current;
	struct sigaction	action;
	int					pid;

	if (argc != 3)
	{
		ft_printf("Error: invalid number of arguments.\n");
		ft_printf("Usage: %s <server PID> \"message\"\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: invalid PID.\n");
		ft_printf("Usage: %s <server PID> \"message\"\n", argv[0]);
		return (1);
	}
	if (initialize_handler(&action))
		return (1);
	current = argv[2];
	g_ready = 1;
	while (*current != '\0')
		send_char(pid, *current++);
	send_char(pid, '\0');
}
