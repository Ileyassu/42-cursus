/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:21:27 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/01/13 20:27:07 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handle_signal(int signalmsg)
{
	static int	bit_counter;
	static char	character;

	if (SIGUSR1 == signalmsg)
	{
		bit_counter++;
		character <<= 1;
		character |= 1;
	}
	else if (SIGUSR2 == signalmsg)
	{
		bit_counter++;
		character <<= 1;
	}
	if (bit_counter == 8)
	{
		ft_printf("%c", character);
		bit_counter = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;

	(void)av;
	server_pid = getpid();
	if (ac != 1)
	{
		ft_printf("Check input");
		return (0);
	}
	ft_printf("Server PID : %d\n", server_pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
