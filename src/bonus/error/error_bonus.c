/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 02:52:52 by gmachado          #+#    #+#             */
/*   Updated: 2022/08/06 03:13:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>

void	send_error(int pid, int sig_num)
{
	if (sig_num == SIGUSR1)
		ft_printf("Error: failed to send signal SIGUSR1 to PID %i\n", pid);
	if (sig_num == SIGUSR2)
		ft_printf("Error: failed to send signal SIGUSR2 to PID %i\n", pid);
	else
		ft_printf(
			"Error: unknown signal error sending signal to PID %i\n", pid);
	exit(1);
}
