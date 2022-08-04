/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:48:28 by gmachado          #+#    #+#             */
/*   Updated: 2022/08/04 03:59:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client_bonus.h>

static void	send_char(int pid, char ch)
{
	int	pos;

	pos = 7;
	while (pos >= 0)
	{
		if (ch & (1 << pos--))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
	}
}

static void	empty_handler(int sig_num)
{
	(void)sig_num;
}

int	main(int argc, char *argv[])
{
	char				*current;
	int					pid;
	struct sigaction	action;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID of server> \"message\"\n", argv[0]);
		return (1);
	}
	action.sa_handler = empty_handler;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	pid = ft_atoi(argv[1]);
	current = argv[2];
	while (*current != '\0')
	{
		send_char(pid, *current++);
	}
	send_char(pid, '\0');
}
