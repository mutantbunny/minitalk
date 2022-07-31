/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:42:22 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/31 18:17:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void sigusr1_handler(int sig_num)
{

}

int main(void)
{
	struct sigaction action;

	action.sa_handler = sigusr1_handler;
	sigemptyset
	return (0);
}
