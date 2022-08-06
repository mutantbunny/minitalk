/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:42:22 by gmachado          #+#    #+#             */
/*   Updated: 2022/08/06 03:03:45 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>

void	sig_handler(int sig_num, siginfo_t *info, void *context)
{
	static char	ch = 0;
	static int	pos = 0;

	(void)context;
	ch <<= 1;
	if (sig_num == SIGUSR2)
		ch |= (char)1;
	if (pos != 7)
		pos++;
	else
	{
		if (ch)
			write(1, &ch, 1);
		else
			write(1, "\n", 1);
		pos = 0;
		ch = '\0';
	}
	if (kill(info->si_pid, SIGUSR1))
		send_error(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	int					err;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_handler;
	err = sigemptyset(&action.sa_mask);
	err |= sigaddset(&action.sa_mask, SIGUSR1);
	err |= sigaddset(&action.sa_mask, SIGUSR2);
	err |= sigaction(SIGUSR1, &action, NULL);
	err |= sigaction(SIGUSR2, &action, NULL);
	if (err)
	{
		ft_printf("Error setting up signal handlers");
		return (1);
	}
	ft_printf("Server PID: %i\n", getpid());
	while (1)
		pause();
	return (0);
}
