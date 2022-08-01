/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:41:11 by gmachado          #+#    #+#             */
/*   Updated: 2022/08/01 03:17:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// Enable the functionality in the Single UNIX Specification Version 4.
// See https://pubs.opengroup.org/onlinepubs/9699919799/xrat/
// V4_xsh_chap02.html#tag_22_02_02.
// This macro is necessary to enable the use of explicity allowed
// function sigaction().
# define _XOPEN_SOURCE 600

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <libft.h>

#endif
