/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:42:22 by gmachado          #+#    #+#             */
/*   Updated: 2022/08/01 03:31:21 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	sig_handler(int sig_num)
{
	static char	ch = 0;
	static int	pos = 0;

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
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("Server PID: %i\n", getpid());
	while (1)
		pause();
	return (0);
}
