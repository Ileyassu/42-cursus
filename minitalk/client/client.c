/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:21:16 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/01/13 20:49:52 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_signals(int server_pid, char c)
{
	int	bit_counter;

	bit_counter = 7;
	while (bit_counter >= 0)
	{
		if ((c >> bit_counter) & 1)
		{
			kill(server_pid, SIGUSR1);
		}
		else
		{
			kill(server_pid, SIGUSR2);
		}
		usleep(400);
		bit_counter--;
	}
}

static int	input_is_correct(int ac, char **av)
{
	int	is_correct;

	is_correct = 0;
	if (ac != 3)
	{
		ft_printf("Please correct input 1\n");
	}
	else if (!ft_isdigit(av[1]))
	{
		ft_printf("Please correct input 2\n");
	}
	else if (!av[2])
	{
		ft_printf("Please correct input 3\n");
	}
	else
		is_correct = 1;
	return (is_correct);
}

int	main(int ac, char **av)
{
	char	*str;
	int		i;
	int		server_pid;

	if (!input_is_correct(ac, av))
		return (0);
	i = 0;
	server_pid = ft_atoi(av[1]);
	str = ft_strdup(av[2]);
	if (!str)
		free(str);
	while (str[i] != '\0')
	{
		send_signals(server_pid, str[i]);
		i++;
	}
	free(str);
	send_signals(server_pid, '\n');
	return (0);
}
